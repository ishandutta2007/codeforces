#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define T9 1000000000
using namespace std;
typedef long long ll;

int uf[100005];
int w[100005];
int nc;

int find(int x){
	if(uf[x]<0)return x;
	return uf[x]=find(uf[x]);
}

void join(int x, int y){
	x=find(x);y=find(y);
	if(x==y)return;
	nc--;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];
	uf[y]=x;
}

int n,m,p,q;
pair<pair<int,int>,int> e[100005];
vector<pair<int,int> > r;
priority_queue<pair<int,int> > s;

int main(){
	scanf("%d%d%d%d",&n,&m,&p,&q);
	memset(uf,-1,sizeof(uf));
	nc=n;
	fore(i,0,m){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);x--;y--;
		e[i]=mp(mp(x,y),c);
		join(x,y);
	}
	if(nc<q)puts("NO");
	else if(nc==q){
		if(p==0)puts("YES");
		else if(m==0)puts("NO");
		else {
			puts("YES");
			fore(i,0,p)printf("%d %d\n",e[0].fst.fst+1,e[0].fst.snd+1);
		}
	}
	else {
		if(nc-q>p){puts("NO");return 0;}
		fore(i,0,m){
			int k=find(e[i].fst.fst);
			w[k]+=e[i].snd;
			w[k]=min(w[k],T9);
		}
		fore(i,0,n)if(uf[i]<0)s.push(mp(-w[i],i));
		while(nc>q){
			auto p0=s.top();s.pop();
			auto p1=s.top();s.pop();
			r.pb(mp(p0.snd,p1.snd));
			s.push(mp(max(2LL*(p0.fst+p1.fst)-1,-1LL*T9),p0.snd));
			nc--;
		}
		while(r.size()!=p)r.pb(r[0]);
		puts("YES");
		for(auto p:r)printf("%d %d\n",p.fst+1,p.snd+1);
	}
	return 0;
}