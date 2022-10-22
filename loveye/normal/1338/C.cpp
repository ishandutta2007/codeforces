#include<cstdio>
#include<array>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1e5+5;
int t;
ll n;
typedef array<ll,3> arr;
arr getarr(ll n,ll lim) {
	if(lim==1) return arr{0,0,0};
	ll nn=n&(lim>>2)-1;
	arr ret=getarr(nn,lim>>2);
	ll t1=n&lim>>2,t2=n&lim>>1;
	if(!t1&&!t2) return ret;
	int k=(t1?(t2?2:0):1);
	while(ret[k]!=nn) swap(ret[0],ret[1]),swap(ret[1],ret[2]);
	ret[0]|=lim>>2; ret[1]|=lim>>1;
	ret[2]|=lim>>2|lim>>1;
	return ret;
}
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		ll lim=1;
		while(n>=lim) lim<<=2;
		ll nn=(n-(lim>>2))/3;;
		arr t=getarr(nn,lim>>2);
		while(t[0]!=nn) swap(t[0],t[1]),swap(t[1],t[2]);
		if(n%3==1) cout<<(t[0]|lim>>2)<<endl;
		else if(n%3==2) cout<<(t[1]|lim>>1)<<endl;
		else cout<<(t[2]|lim>>2|lim>>1)<<endl;
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}