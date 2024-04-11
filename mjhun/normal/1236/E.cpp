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
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n,m;
int a[100005];
vector<int> w[200005];
vector<int> dp[200005];

int f(int x, int t){
	int k=upper_bound(w[x+t].begin(),w[x+t].end(),x)-w[x+t].begin();
	if(k==0)return 0;
	k--;
	int& r=dp[x+t][k];
	if(r>=0)return r;
	int x2=w[x+t][k];
	int t2=x+t+1-x2;
	return r=1+f(x2,t2);
}

ll doit(){
	fore(i,0,n+m+1)w[i].clear();
	fore(i,0,m)w[i+1+a[i]].pb(a[i]);
	fore(i,0,n+m+1){
		dp[i].resize(SZ(w[i]));
		fill(dp[i].begin(),dp[i].end(),-1);
		sort(w[i].begin(),w[i].end());
	}
	ll r=0;
	fore(i,1,n){
		int k=f(i,0);
		int j=max(i-m-1+k,0);
		r+=i-j;
	}
	return r;
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,m)scanf("%d",a+i),a[i]--;
	if(n==1){puts("0");return 0;}
	ll r=n+doit();
	fore(i,0,m)a[i]=n-1-a[i];
	r+=doit();
	printf("%lld\n",r);
	return 0;
}