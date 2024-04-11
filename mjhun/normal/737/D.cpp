#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define INF ((1<<30)-1)
using namespace std;
typedef long long ll;

// dp: posicion del primero (4000) , diferencia entre lo que avanzaron los dos (100) , cuanto avanzo el ultimo (100)
int dp[4005][100][100];
bool vis[4005][100][100];
int sp[4005];
int x[4005];
int n;

int f(int k0, int d, int l){
	if(vis[k0][d][l])return dp[k0][d][l];
	vis[k0][d][l]=true;
	int k1=n-1-k0-d;
	if(l>k1-k0+1)return dp[k0][d][l]=0;
	int rr;
	if(l>k1-(k0+l)+1)rr=0;
	else {
		rr=sp[k1+1]-sp[k1+1-l]-f(k0+l,d,l);
		if(l+1<=k1-(k0+l)+1){
			rr=max(rr,sp[k1+1]-sp[k1+1-(l+1)]-f(k0+l,d+1,l+1));
		}
	}
	int r=sp[k0+l]-sp[k0]-rr;
	if(l+1<=k1-k0+1){
		if(l+1>k1-(k0+l+1)+1)rr=0;
		else {
			rr=sp[k1+1]-sp[k1+1-(l+1)]-f(k0+l+1,d,l+1);
			if(l+2<=k1-(k0+l+1)+1){
				rr=max(rr,sp[k1+1]-sp[k1+1-(l+2)]-f(k0+l+1,d+1,l+2));
			}
		}
		r=max(r,sp[k0+l+1]-sp[k0]-rr);
	}
	return dp[k0][d][l]=r;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",x+i);
	fore(i,0,n)sp[i+1]=sp[i]+x[i];
	printf("%d\n",f(0,0,1));
	return 0;
}