#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define mp make_pair
using namespace std;

int n;
int dp[4][128], a[128];
int f(int w, int i) {
	if(i==n) return 0;
	if(dp[w][i]>-1) return dp[w][i];
	int r=f(0,i+1)+1;
	if(a[i]==1||a[i]==3) {
		if(w!=1) r=min(r,f(1,i+1));
	}
	if(a[i]==2||a[i]==3) {
		if(w!=2) r=min(r,f(2,i+1));
	}
	return dp[w][i]=r;
}

int main() {
	scanf("%d",&n);
	fore(i,0,n) scanf("%d",a+i);
	memset(dp,-1,sizeof dp);
	cout<<f(0,0)<<endl;
}