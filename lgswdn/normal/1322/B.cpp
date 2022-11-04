#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=4e5+9;
int n,a[N],b[N],ans;

int tp(int x,int y) {
	if(x>y) return 0;
	int l=1,r=1,ans=0;
	per(i,n,1) {
		while(l<=n&&b[l]+b[i]<x) l++;
		while(r<=n&&b[r]+b[i]<=y) r++;
		ans+=r-l; if(l<=i&&i<r) ans--;
	}
	return ans/2%2;
}

signed main() {
	n=read();
	rep(i,1,n) a[i]=read();
	rep(k,0,25) {
		int s=(1<<(k+1));
		rep(i,1,n) b[i]=a[i]%s;
		sort(b+1,b+n+1);
		int p=tp(1<<k,(1<<(k+1))-1)^tp(3<<k,(1<<(k+2))-2);
		if(p) ans+=(1<<k);
	}
	printf("%lld\n",ans);
	return 0;
}