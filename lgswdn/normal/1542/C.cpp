#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;
typedef bitset<509> bset;
typedef pair<bset,bset> v2;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int mod=1e9+7;

int lcm(int a,int b) {
	return a/__gcd(a,b)*b;
}

signed main() {
	int T=read();
	while(T--) {
		int n=read(), r=1, d=2, ans=0;
		while(r<=n) {
			ans+=d*(n/r-n/lcm(r,d));
			r=lcm(r,d), d++;
			//cout<<r<<" "<<d<<endl;
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}