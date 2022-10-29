#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int n,m;
vector<pair<pair<int,int>,int> > e0[100005],e1[100005];
int a[100005];
double p[5005];
int w[5005],mx;
vector<int> g[5005];
stack<int> st;
bool vis[5005][10005];
double dp[5005][10005];

double f(int x, int k){
	if(vis[x][k])return dp[x][k];
	vis[x][k]=true;
	double r=0;
	if(w[x]<=mx+k-5001){
		double s=1-p[x];
		for(int y:g[x])s*=f(y,k);
		r+=s;
	}
	if(w[x]+1<=mx+k-5001){
		double s=p[x];
		for(int y:g[x])s*=f(y,k-1);
		r+=s;
	}
	return dp[x][k]=r;
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%d",a+i),mx=max(mx,a[i]);
	fore(i,0,m){
		int s,e;
		scanf("%d%d%lf",&s,&e,p+i+1);s--;
		e0[s].pb(mp(mp(-e,i),i+1));
		e1[e].pb(mp(mp(-s,-i),i+1));
	}
	st.push(0);
	fore(i,0,n){
		sort(e1[i].begin(),e1[i].end());sort(e0[i].begin(),e0[i].end());
		for(auto p:e1[i]){
			int x=p.snd;
			assert(st.top()==x);st.pop();
		}
		for(auto p:e0[i]){
			int x=p.snd;
			g[st.top()].pb(x);
			st.push(x);
		}
		w[st.top()]=max(w[st.top()],a[i]);
	}
	m++;
	double r=mx;
	fore(i,0,m)r+=1-f(0,5001+i);
	printf("%.12lf\n",r);
	return 0;
}