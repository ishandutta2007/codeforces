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

const int N=109;
int T,n,a[N];

signed main() {
	T=read();
	while(T--) {
		n=read();
		rep(i,1,n) a[i]=read();
		int mx=0,sum=0;
		rep(i,1,n) mx=max(mx,a[i]), sum+=a[i];
		if(mx*2>sum) puts("T");
		else if(sum%2==0) puts("HL");
		else puts("T");
	}
	return 0;
}