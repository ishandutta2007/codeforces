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

int n,k;
int q0[100005],q1[100005];
int h[16];
int dp[505][5005];

int f(int i, int j){
	int& r=dp[i][j];
	if(r>=0)return r;
	r=0;
	fore(l,0,min(j,k)+1){
		r=max(r,h[l]+f(i-1,j-l));
	}
	return r;
}

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,n*k){
		int c;
		scanf("%d",&c);
		q0[c]++;
	}
	fore(i,0,n){
		int c;
		scanf("%d",&c);
		q1[c]++;
	}
	fore(i,1,k+1)scanf("%d",h+i);
	mset(dp,-1);mset(dp[0],0);
	int r=0;
	fore(i,0,100005)r+=f(q1[i],q0[i]);
	printf("%d\n",r);
	return 0;
}