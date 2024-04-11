#include <bits/stdc++.h>
#define INF (1<<30)
#define mp make_pair
#define fst first
#define snd second
using namespace std;

int ft[1<<19];
int query(int b) {
	int sum = 0; for (;b;b-=(b&(-b)))sum+=ft[b];
	return sum;
}
void upd(int k, int v) {
	for (;k<(1<<19);k+=(k&(-k)))ft[k]+=v;
}

set<pair<int,pair<int,int> > > vx;
set<pair<int,pair<int,int> > > vy;
set<pair<int,pair<int,int> > > wx;
set<pair<int,pair<int,int> > > wy;
vector<pair<int,pair<int,pair<int,int> > > > e;
set<int> xs;
map<int,int> id;
int n;

void work(set<pair<int,pair<int,int> > >& v, set<pair<int,pair<int,int> > >& w){
	int x=INF,y0,y1;
	for(set<pair<int,pair<int,int> > >::iterator it=v.begin();it!=v.end();++it){
		if(it->fst==x&&it->snd.fst<=y1){
			y1=max(y1,it->snd.snd);
		}
		else {
			if(x!=INF)w.insert(mp(x,mp(y0,y1)));
			x=it->fst;
			y0=it->snd.fst;y1=it->snd.snd;
		}
	}
	if(x!=INF)w.insert(mp(x,mp(y0,y1)));
	/*for(set<pair<int,pair<int,int> > >::iterator it=w.begin();it!=w.end();++it){
		printf(" %d %d %d\n",it->fst,it->snd.fst,it->snd.snd);
	}*/
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int x0,y0,x1,y1;
		scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
		if(x0==x1){
			if(y0>y1)swap(y0,y1);
			vy.insert(mp(x0,mp(y0,y1)));
		}
		else {
			if(x0>x1)swap(x0,x1);
			vx.insert(mp(y0,mp(x0,x1)));
		}
	}
	work(vx,wx);work(vy,wy);
	long long r=0;
	for(set<pair<int,pair<int,int> > >::iterator it=wx.begin();it!=wx.end();++it){
		e.push_back(mp(it->snd.fst,mp(0,mp(it->fst,1))));
		e.push_back(mp(it->snd.snd,mp(2,mp(it->fst,-1))));
		xs.insert(it->fst);
		r+=it->snd.snd-it->snd.fst + 1;
	}
	for(set<pair<int,pair<int,int> > >::iterator it=wy.begin();it!=wy.end();++it){
		e.push_back(mp(it->fst,mp(1,mp(it->snd.fst,it->snd.snd))));
		xs.insert(it->snd.fst);
		xs.insert(it->snd.snd);
		r+=it->snd.snd-it->snd.fst + 1;
	}
	int i=2;
	for(set<int>::iterator it=xs.begin();it!=xs.end();++it,++i){
		id[*it]=i;
	}
	sort(e.begin(),e.end());
	for(i=0;i<e.size();++i){
		if(e[i].snd.fst==1){
			r-=query(id[e[i].snd.snd.snd])-query(id[e[i].snd.snd.fst]-1);
		}
		else {
			upd(id[e[i].snd.snd.fst],e[i].snd.snd.snd);
		}
	}
	cout<<r<<endl;
	return 0;
}