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
int ans,n,k,c[N];
priority_queue<int>s;

signed main() {
	n=read(), k=read();
	rep(i,1,n) c[i]=read();
	sort(c+1,c+n+1,greater<int>());
	rep(i,1,k+1) s.push(0);
	rep(i,1,n) {
		int x=s.top(); s.pop();
		ans+=x, x+=c[i]; s.push(x);
	}
	printf("%lld\n",ans);
	return 0;
}