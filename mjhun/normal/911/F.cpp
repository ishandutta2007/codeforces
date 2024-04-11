#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

vector<int> g[200005];
int n,d[200005],d0[200005],d1[200005];
queue<int> q;
int x0,x1;

void dfs(int x, int f, int* d){
	for(int y:g[x]){
		if(y==f)continue;
		d[y]=d[x]+1;
		dfs(y,x,d);
	}
}

vector<pair<int,int> > r;

int main(){
	scanf("%d",&n);
	fore(_,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);d[x]++;d[y]++;
	}
	dfs(0,-1,d1);x0=max_element(d1,d1+n)-d1;
	dfs(x0,-1,d0);x1=max_element(d0,d0+n)-d0;
	d1[x1]=0;dfs(x1,-1,d1);
	fore(i,0,n)if(i!=x0&&i!=x1&&d[i]==1)q.push(i);
	ll s=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		if(d0[x]>d1[x]){
			r.pb(mp(x0,x));
			s+=d0[x];
		}
		else {
			r.pb(mp(x1,x));
			s+=d1[x];
		}
		for(int y:g[x]){
			d[y]--;
			if(d[y]==1)q.push(y);
		}
	}
	int x=x0;
	while(x!=x1){
		s+=d1[x];
		r.pb(mp(x1,x));
		for(int y:g[x]){
			d[y]--;
			if(d[y]==1||y==x1){x=y;break;}
		}
	}
	printf("%lld\n",s);
	for(auto p:r)printf("%d %d %d\n",p.fst+1,p.snd+1,p.snd+1);
	return 0;
}