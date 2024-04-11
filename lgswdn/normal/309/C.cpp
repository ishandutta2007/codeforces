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

const int N=1e6+9;

int n,m,a[N],b[N],c[N];

bool work(int p) {
	int cnt=0;
	per(i,30,b[p]) cnt=(cnt<<1)+c[i];
	int pos=b[p];
	rep(i,p,m) {
		while(pos>b[i]) cnt=(cnt<<1)+c[--pos];
		if((--cnt)<0) return 0;
	}
	return 1;
}

signed main() {
	n=read(), m=read();
	rep(i,1,n) {
		a[i]=read();
		rep(j,0,30) if(a[i]&(1ll<<j)) c[j]++;
	}
	rep(i,1,m) b[i]=read();
	sort(b+1,b+m+1,greater<int>());
	int res=0;
	for(int l=1,r=m,mid=l+r>>1;l<=r;mid=l+r>>1) {
		if(work(mid)) r=mid-1, res=m-mid+1;
		else l=mid+1;
	} printf("%lld\n",res);
	return 0;
}