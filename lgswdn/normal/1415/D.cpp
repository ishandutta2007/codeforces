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

const int N=1e6+9;
int n,a[N],b[N];

signed main() {
	n=read();
	rep(i,1,n) a[i]=read();
	bool flag=0;
	rep(i,2,n) if(a[i-1]>a[i]) flag=1;
	if(flag) return puts("0"), 0;
	rep(i,1,n-2) if(a[i]>(a[i+1]^a[i+2])) flag=1;
	rep(i,3,n) if((a[i-2]^a[i-1])>a[i]) flag=1;
	if(flag) return puts("1"), 0;
	rep(i,1,n) b[i]=b[i-1]^a[i];
	int ans=n+1;
	rep(l,1,n-1) rep(m,l,n-1) rep(r,m+1,n) {
		if((b[m]^b[l-1])>(b[r]^b[m])) ans=min(ans,r-l-1);
	}
	if(ans>n) ans=-1;
	printf("%lld\n",ans);
	return 0;
}