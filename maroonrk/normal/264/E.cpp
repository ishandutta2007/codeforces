#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair

typedef pair<int,int> pii;

struct Seg{
	vector<int> d;
	int s;
	Seg(int n){
		s=1;
		while(s<n)s*=2;
		d.resize(s*2,0);
	}
	int Get(int b,int e,int l,int r,int i){
		if(e<=l||r<=b)
			return 0;
		if(b<=l&&r<=e)
			return d[i];
		return max(Get(b,e,l,(l+r)/2,i*2),Get(b,e,(l+r)/2,r,i*2+1));
	}
	int Get(int b,int e){
		return Get(b,e,0,s,1);
	}
	void Set(int i,int v){
		i+=s;
		d[i]=v;
		while((i/=2)>0)
			d[i]=max(d[i*2],d[i*2+1]);
	}
};

struct Query{
	int t,p,h,x;
};

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> yx(m+10,-1);
	vector<Query> qs(m);
	REP(i,m){
		scanf("%d",&qs[i].t);
		if(qs[i].t==1)
			scanf("%d%d",&qs[i].p,&qs[i].h);
		else
			scanf("%d",&qs[i].x);
	}
	Seg hrz(n),vrt(m+10);
	priority_queue<pii,vector<pii>,greater<pii>> xy;
	pii buf[10];
	REP(i,m){
		if(qs[i].t==1){
			yx[(--qs[i].h)+=m-i]=--qs[i].p;
			FOR(j,m-i,qs[i].h)
				if(yx[j]!=-1)
					hrz.Set(yx[j],0);
			xy.push(MP(qs[i].p,qs[i].h));
			for(int j=qs[i].h;j>=m-i;j--)
				if(yx[j]!=-1){
					int v=hrz.Get(yx[j]+1,n)+1;
					hrz.Set(yx[j],v);
					vrt.Set(j,v);
				}
		}else{
			REP(j,qs[i].x){
				buf[j]=xy.top();
				xy.pop();
				vrt.Set(buf[j].second,0);
			}
			yx[buf[qs[i].x-1].second]=-1;
			hrz.Set(buf[qs[i].x-1].first,0);
			for(int j=qs[i].x-2;j>=0;j--){
				int v=vrt.Get(buf[j].second+1,m+10)+1;
				vrt.Set(buf[j].second,v);
				hrz.Set(buf[j].first,v);
				xy.push(buf[j]);
			}
		}
		int vm=vrt.Get(0,m+10),hm=hrz.Get(0,n);
		assert(vm==hm);
		printf("%d\n",vm);
	}
}