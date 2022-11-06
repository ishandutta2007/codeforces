#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll dp[505][505];

int a[505],b[505];
int am[505],bm[505];
//int ac[505],bc[505];
int sumpt[505];
int n,k; 

int mod(int n){
	while(n>=k)n-=k;
	while(n<0)n+=k;
	return n;
}

ll f(int x, int y){
	ll &r=dp[x][y];
	if(r>=0)return r;
	if(x==n)return r=0;
	int ta=y,tb=mod(sumpt[x]-ta);
	r=0;
	fore(i,0,k+1){
		if(a[x]>=i&&b[x]>=k-i){
			r=max(r,f(x+1,mod(ta+am[x]-i))+1+(ta+a[x]-i)/k+(tb+b[x]-(k-i))/k);
		}
	}
	r=max(r,f(x+1,mod(ta+am[x]))+(ta+a[x])/k+(tb+b[x])/k);
	return r;
}

int main(){FIN;
	cin>>n>>k;
	mset(dp,-1);
	fore(i,0,n)cin>>a[i]>>b[i];
	fore(i,0,n){
		sumpt[i+1]=(sumpt[i]+a[i]+b[i])%k;
		am[i]=a[i]%k; //ac[i]=a[i]/k;
		bm[i]=b[i]%k; //bc[i]=b[i]/k;
	}
	cout<<f(0,0);
	
	return 0;
}