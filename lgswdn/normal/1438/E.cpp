#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9;
typedef pair<int,int> pii;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,a[N],ans;
set<pii>s;

int main() {
	n=read();
	rep(i,1,n) a[i]=read();
	rep(l,1,n) {
		int sum=0,x=(1<<30);
		while(x>a[l]) x>>=1; x=(x<<1)-1;
		rep(r,l+1,n-1) {
			sum+=a[r];
			if(sum>x) break;
			if((a[l]^a[r+1])==sum) s.insert(make_pair(l+1,r));
		}
	}
	per(r,n,1) {
		int sum=0,x=(1<<30);
		while(x>a[r]) x>>=1; x=(x<<1)-1;
		per(l,r-1,2) {
			sum+=a[l];
			if(sum>x) break;
			if((a[r]^a[l-1])==sum) s.insert(make_pair(l,r-1));
		}
	}
	printf("%d\n",s.size());
	return 0;
}