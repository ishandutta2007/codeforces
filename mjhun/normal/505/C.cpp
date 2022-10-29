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
#define mset(x,a) (memset((x),(a),sizeof(x)))
#define mcpy(x,y) (memcpy((x),(y),sizeof(x)))
using namespace std;
typedef long long ll;

int dp[30005][512];
int q[30005];
int o;

int f(int k, int t){
	if(k>30000)return 0;
	if(dp[k][t-o]>=0)return dp[k][t-o];
	return dp[k][t-o]=q[k]+max(f(k+max(t-1,1),max(t-1,1)),max(f(k+t,t),f(k+t+1,t+1)));
}

int main(){
	int n,d;
	scanf("%d%d",&n,&d);
	o=d;
	for(int i=d;o>1&&i<=30000;o--,i+=o);
	while(n--){
		int t;
		scanf("%d",&t);
		q[t]++;
	}
	mset(dp,-1);
	printf("%d\n",f(d,d));
	return 0;
}