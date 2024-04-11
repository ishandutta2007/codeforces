#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>
#include<cassert>
using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)
#define REPSZ(i,v) REP(i,SZ(v))
#define FORSZ(i,a,v) FOR(i,a,SZ(v))

typedef long long ll;

typedef struct PathItem {
	int part; // part==0 for an evil shortcut
	int from,to; // always go in direction from,from+1,... so from>to means that the path will wrap (should only happen when it is not an evil shortcut)
	PathItem(int part,int from,int to):part(part),from(from),to(to) {}
	PathItem(int from,int to):part(0),from(from),to(to) {}
} PathItem;

int ncastles,ngoodcastles;
vector<int> partlen; // part 0 is the good road.
vector<int> partnr;
vector<int> partoffset;
vector<bool> isgood;
vector<vector<int> > nodenr;

vector<int> gnomesongoodroad;
vector<vector<pair<int,int> > > val;

pair<int,int> get(int p,int x,int l,int h,int ll,int hh) {
//	printf("\get(%d,%d,%d,%d,%d,%d)\n",p,x,l,h,ll,hh);
	if(ll<l) ll=l; if(hh>h) hh=h; if(ll>hh) return MP(0,0);
	if(l==ll&&h==hh) return val[p][x];
	int m=l+(h-l)/2;
	pair<int,int> a=get(p,2*x+1,l,m,ll,hh);
	pair<int,int> b=get(p,2*x+2,m+1,h,ll,hh);
	return MP(a.first+b.first,a.second+b.second);
}

void clear(int p,int x,int l,int h,int ll,int hh) {
	if(ll<l) ll=l; if(hh>h) hh=h; if(ll>hh||val[p][x].first==0) return;
	if(l==h) {
		val[p][x].first=0;
		if(p==0) {
			if(val[p][x].second==1) {
				gnomesongoodroad[l]=0;
			} else {
				clear(l+1,0,0,partlen[l+1]-2,0,partlen[l+1]-2);
			}
		}
	} else {
		int m=l+(h-l)/2;
		clear(p,2*x+1,l,m,ll,hh);
		clear(p,2*x+2,m+1,h,ll,hh);
		val[p][x]=MP(val[p][2*x+1].first+val[p][2*x+2].first,val[p][2*x+1].second+val[p][2*x+2].second);
	}
}

void update(int p,int x,int l,int h,int at) {
//	printf("\tupdate(%d,%d,%d,%d,%d)\n",p,x,l,h,at);
	if(at<l||at>h) return;
	if(l==h) {
		if(p==0) {
			val[p][x]=MP(gnomesongoodroad[l],1);
			pair<int,int> other=get(l+1,0,0,partlen[l+1]-2,0,partlen[l+1]-2);
			if(other<val[p][x]) val[p][x]=other;
		} else {
			++val[p][x].first;
		}
	} else {
		int m=l+(h-l)/2;
		update(p,2*x+1,l,m,at);
		update(p,2*x+2,m+1,h,at);
		val[p][x]=MP(val[p][2*x+1].first+val[p][2*x+2].first,val[p][2*x+1].second+val[p][2*x+2].second);
	}
}

void init(int p,int x,int l,int h) {
//	printf("\tinit(%d,%d,%d,%d)\n",p,x,l,h);
	if(l==h) {
		while(x>=SZ(val[p])) val[p].PB(MP(0,0));
		val[p][x]=MP(0,1);
	} else {
		int m=l+(h-l)/2;
		init(p,2*x+1,l,m);
		init(p,2*x+2,m+1,h);
		val[p][x]=MP(val[p][2*x+1].first+val[p][2*x+2].first,val[p][2*x+1].second+val[p][2*x+2].second);
	}
}

pair<int,int> get(int p,int from,int to) {
	if(from>to) {
		pair<int,int> a=get(p,from,partlen[p]);
		pair<int,int> b=get(p,0,to);
		return MP(a.first+b.first,a.second+b.second);
	}
	return get(p,0,0,partlen[p]-(p==0?1:2),from,to-1);
}

void clear(int p,int from,int to) {
	if(from>to) {
		clear(p,from,partlen[p]);
		clear(p,0,to);
	}
	clear(p,0,0,partlen[p]-(p==0?1:2),from,to-1);
	if(p!=0) update(0,0,0,partlen[0]-1,p-1);
}

void update(int p,int at) {
//	printf("update(%d,%d)\n",p,at);
	if(p==0) {
		++gnomesongoodroad[at];
		update(0,0,0,partlen[0]-1,at);
	} else {
		update(p,0,0,partlen[p]-2,at);
		update(0,0,0,partlen[0]-1,p-1);
	}
}

void init(int p) {
	init(p,0,0,partlen[p]-(p==0?1:2));
}

vector<vector<PathItem> > getpaths(int from,int to) {
	vector<vector<PathItem> > ret;
	if(!isgood[from]&&!isgood[to]&&partnr[from]==partnr[to]) {
		if(partoffset[from]>partoffset[to]) swap(from,to);
		{ vector<PathItem> path; path.PB(PathItem(partnr[from],partoffset[from],partoffset[to])); ret.PB(path); }
		int nfrom=nodenr[partnr[from]][0],nto=nodenr[partnr[from]][partlen[partnr[from]]-1];
		REP(globaldir,2) {
			vector<PathItem> path;
			path.PB(PathItem(partnr[from],0,partoffset[from]));
			path.PB(globaldir==0?PathItem(partoffset[nfrom],partoffset[nto]):PathItem(partoffset[nto],partoffset[nfrom]));
			path.PB(PathItem(partnr[from],partoffset[to],partlen[partnr[from]]-1));
			ret.PB(path);
		}
	} else {
		REP(frompartdir,isgood[from]?1:2) {
			int nfrom=isgood[from]?from:frompartdir==0?nodenr[partnr[from]][0]:nodenr[partnr[from]][partlen[partnr[from]]-1];
			REP(topartdir,isgood[to]?1:2) {
				int nto=isgood[to]?to:topartdir==0?nodenr[partnr[to]][0]:nodenr[partnr[to]][partlen[partnr[to]]-1];
				REP(globaldir,nfrom==nto?1:2) {
					vector<PathItem> path;
					if(!isgood[from]) path.PB(frompartdir==0?PathItem(partnr[from],0,partoffset[from]):PathItem(partnr[from],partoffset[from],partlen[partnr[from]]-1));
					if(nfrom!=nto) path.PB(globaldir==0?PathItem(partoffset[nfrom],partoffset[nto]):PathItem(partoffset[nto],partoffset[nfrom]));
					if(!isgood[to]) path.PB(topartdir==0?PathItem(partnr[to],0,partoffset[to]):PathItem(partnr[to],partoffset[to],partlen[partnr[to]]-1));
					ret.PB(path);
				}
			}
		}
	}
	return ret;
}

pair<int,int> getpathcost(vector<PathItem> path) {
	pair<int,int> ret=MP(0,0);
	REPSZ(i,path) {
		pair<int,int> cur=get(path[i].part,path[i].from,path[i].to);
		ret.first+=cur.first; ret.second+=cur.second;
	}
	return ret;
}

bool islexsmaller(vector<PathItem> a,vector<PathItem> b,int at) {
	for(int i=0;i<SZ(a)&&i<SZ(b);++i) {
		if(a[i].part==b[i].part&&a[i].from==b[i].from&&a[i].to==b[i].to) {
			if(nodenr[a[i].part][a[i].from]==at) at=nodenr[a[i].part][a[i].to]; else at=nodenr[a[i].part][a[i].from];
			continue;
		}
		int aa = nodenr[a[i].part][a[i].from]==at ? (a[i].from+1)%partlen[a[i].part] : (a[i].to+partlen[a[i].part]-1)%partlen[a[i].part], aaa=nodenr[a[i].part][aa];
		int bb = nodenr[b[i].part][b[i].from]==at ? (b[i].from+1)%partlen[b[i].part] : (b[i].to+partlen[b[i].part]-1)%partlen[b[i].part], bbb=nodenr[b[i].part][bb];
		int ai=i,bi=i;
//		printf("(%d,%d) -> %d / (%d,%d) -> %d\n",a[ai].part,aa,aaa,b[bi].part,bb,bbb);
		if(aaa!=bbb) return aaa<bbb;
		int alen=a[i].from<a[i].to?a[i].to-a[i].from:partlen[a[i].part]-a[i].from+a[i].to;
		int blen=b[i].from<b[i].to?b[i].to-b[i].from:partlen[b[i].part]-b[i].from+b[i].to;
		assert(alen!=blen);
		if(alen<blen) {
			assert(i<SZ(a)); ++ai;
			int nat; if(nodenr[a[i].part][a[i].from]==at) nat=nodenr[a[i].part][a[i].to]; else nat=nodenr[a[i].part][a[i].from];
			aa = nodenr[a[i+1].part][a[i+1].from]==nat ? (a[i+1].from+1)%partlen[a[i+1].part] : (a[i+1].to+partlen[a[i+1].part]-1)%partlen[a[i+1].part], aaa=nodenr[a[i+1].part][aa];
			bb = nodenr[b[i].part][b[i].from]==at ? (b[i].from+alen+1)%partlen[b[i].part] : (b[i].to+partlen[b[i].part]-(alen+1))%partlen[b[i].part], bbb=nodenr[b[i].part][bb];
		} else {
			assert(i+1<SZ(b)); ++bi;
			int nat; if(nodenr[b[i].part][b[i].from]==at) nat=nodenr[b[i].part][b[i].to]; else nat=nodenr[b[i].part][b[i].from];
			aa = nodenr[a[i].part][a[i].from]==at ? (a[i].from+blen+1)%partlen[a[i].part] : (a[i].to+partlen[a[i].part]-(blen+1))%partlen[a[i].part], aaa=nodenr[a[i].part][aa];
			bb = nodenr[b[i+1].part][b[i+1].from]==nat ? (b[i+1].from+1)%partlen[b[i+1].part] : (b[i+1].to+partlen[b[i+1].part]-1)%partlen[b[i+1].part], bbb=nodenr[b[i+1].part][bb];
		}
//		printf("(%d,%d) -> %d / (%d,%d) -> %d\n",a[ai].part,aa,aaa,b[bi].part,bb,bbb);
		assert(aaa!=bbb);
		return aaa<bbb;
	}
	assert(false);
	return false;
}

void removegnomes(vector<PathItem> path) {
	REPSZ(i,path) {
		clear(path[i].part,path[i].from,path[i].to);
	}
}



void run() {
	scanf("%d%d",&ncastles,&ngoodcastles);
	isgood=vector<bool>(ncastles+1);
	partnr=vector<int>(ncastles+1);
	partoffset=vector<int>(ncastles+1);
	partlen=vector<int>(1+ngoodcastles);
	nodenr=vector<vector<int> >(ncastles+1);
	nodenr[0]=vector<int>(ngoodcastles+1);
	partlen[0]=ngoodcastles;
	REP(i,ngoodcastles) {
		scanf("%d",&nodenr[0][i]);
		isgood[nodenr[0][i]]=true;
		partnr[nodenr[0][i]]=0;
		partoffset[nodenr[0][i]]=i;
	}
	FORE(i,1,ngoodcastles) {
		scanf("%d",&partlen[i]);
		nodenr[i]=vector<int>(partlen[i]);
		REP(j,partlen[i]) {
			scanf("%d",&nodenr[i][j]);
			if(j!=0&&j!=partlen[i]-1) {
				isgood[nodenr[i][j]]=false;
				partnr[nodenr[i][j]]=i;
				partoffset[nodenr[i][j]]=j;
			}
		}
	}
	gnomesongoodroad=vector<int>(ngoodcastles,0);
	val=vector<vector<pair<int,int> > >(ngoodcastles+1); REPSZ(i,val) init(i);

//	map<pair<int,int>,int> cnt;
	int q; scanf("%d",&q);	
	REP(qq,q) {
		char type; int from,to; scanf(" %c%d%d",&type,&from,&to);
		if(type=='+') {
//			++cnt[MP(from,to)];
			if(isgood[from]&&isgood[to]) {
				if(partoffset[from]>partoffset[to]) swap(from,to);
				int pos=partoffset[from]==partoffset[to]-1?partoffset[from]:partoffset[to];
				update(0,pos);
			} else {
				if(isgood[from]) swap(from,to);
				int p=partnr[from];
				int pos=min(partoffset[from],!isgood[to]?partoffset[to]:to==nodenr[p][0]?0:partlen[p]);
				update(p,pos);
			}
		}
		if(type=='?') {
//			for(map<pair<int,int>,int>::iterator it=cnt.begin();it!=cnt.end();++it)
//				printf("(%d,%d) = %d\n",it->first.first,it->first.second,it->second);
//			cnt=map<pair<int,int>,int>();
//			printf("processing %c %d %d\n",type,from,to);
			vector<vector<PathItem> > paths = getpaths(from,to);
//			REPSZ(i,paths) { REPSZ(j,paths[i]) { printf("(%d,%d,%d)",paths[i][j].part,paths[i][j].from,paths[i][j].to); } pair<int,int> cur=getpathcost(paths[i]); printf(" = (%d,%d)\n",cur.first,cur.second); }
			vector<PathItem> bestpath=paths[0]; pair<int,int> bestcost=getpathcost(bestpath);
			FORSZ(i,1,paths) {
				pair<int,int> curcost=getpathcost(paths[i]);
				if(curcost<bestcost||curcost==bestcost&&islexsmaller(paths[i],bestpath,from)) { bestpath=paths[i]; bestcost=curcost; }
			}
			removegnomes(bestpath);
//			{ printf("%d:",0); REP(j,partlen[0]) printf(" %d,%d",gnomesongoodroad[j],1); puts(""); }
//			REP(i,ngoodcastles+1) { printf("%d:",i); REP(j,i==0?partlen[i]:partlen[i]-1) printf(" %d,%d",get(i,j,j+1).first,get(i,j,j+1).second); puts(""); }
			printf("%d\n",bestcost.first);
		}
	}

}

int main() {
	run();
	return 0;
}