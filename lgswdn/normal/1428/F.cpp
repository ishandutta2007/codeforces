#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=5e5+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,s,ans,r[N],sz;
char c[N];

signed main() {
	scanf("%lld%s",&n,c+1);
	rep(i,1,n) r[i]=n+1;
	per(i,n,1) {
		if(c[i]=='0') {
			ans+=s;
			for(;sz;r[sz]=i+(sz--));
		}
		else sz++, ans+=(s+=r[sz]-i);
	}
	printf("%lld\n",ans);
	return 0;
}