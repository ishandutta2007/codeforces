#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF ((1<<31)-1)

int h,n,m;
int u[100005],l[100005],r[100005],s[100005];
int x[100005],st[400005];
stack<pair<int,int> > w[100005];
vector<int> g[100005];
int dp[100005];
vector<pair<int,int> > e;


void init(int k, int s, int e){
	st[k]=s;
	if(s+1==e)return;
	int m=(s+e)/2;
	init(2*k,s,m);
	init(2*k+1,m,e);
}

void st_upd(int k, int s, int e, int p, int v){
	if(s+1==e){x[s]=v;return;}
	int m=(s+e)/2;
	if(p<m)st_upd(2*k,s,m,p,v);
	else st_upd(2*k+1,m,e,p,v);
	if(x[st[2*k]]<x[st[2*k+1]])st[k]=st[2*k];
	else st[k]=st[2*k+1];
}

int st_query(int k, int s, int e, int a, int b){
	if(e<=a||s>=b)return -1;
	if(s>=a&&e<=b)return st[k];
	int m=(s+e)/2;
	int r0=st_query(2*k,s,m,a,b);
	int r1=st_query(2*k+1,m,e,a,b);
	if(r0<0)return r1;
	if(r1<0)return r0;
	if(x[r0]<x[r1])return r0;
	return r1;
}

int f(int x){
	if(dp[x]>=0)return dp[x];
	if(x==m+1)return dp[x]=1;
	dp[x]=0;
	for(int y:g[x])dp[x]+=f(y),dp[x]%=MOD;
	return dp[x];
}

int main(){
	scanf("%d%d%d",&h,&n,&m);
	fore(i,0,n)x[i]=h+1,w[i].push(mp(h+1,0));
	init(1,0,n);
	fore(i,0,m){
		scanf("%d%d%d%d",u+i,l+i,r+i,s+i);l[i]--;
		e.pb(mp(-u[i],i));
	}
	s[m]=INF;l[m]=0;r[m]=n;
	e.pb(mp(1,m));
	sort(e.begin(),e.end());
	for(auto _:e){
		int i=_.snd;
		while(1){
			int k=st_query(1,0,n,l[i],r[i]);
			if(x[k]==INF||x[k]>u[i]+s[i])break;
			auto p=w[k].top();w[k].pop();
			g[p.snd].pb(i+1);
			if(w[k].empty())st_upd(1,0,n,k,INF);
			else st_upd(1,0,n,k,w[k].top().fst);
		}
		if(i==m)break;
		if(l[i]==0)w[r[i]].push(mp(u[i],i+1)),st_upd(1,0,n,r[i],u[i]);
		else w[l[i]-1].push(mp(u[i],i+1)),st_upd(1,0,n,l[i]-1,u[i]);
		if(r[i]==n)w[l[i]-1].push(mp(u[i],i+1)),st_upd(1,0,n,l[i]-1,u[i]);
		else w[r[i]].push(mp(u[i],i+1)),st_upd(1,0,n,r[i],u[i]);
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",f(0));
	return 0;
}