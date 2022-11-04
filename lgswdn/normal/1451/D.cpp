#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,d,k;

signed main() {
	T=read();
	while(T--) {
		d=read(), k=read();
		int hd=0,x=0,y=0,p=0;
		rep(i,1,d+1) {
			p+=k;
			if(2*p*p>d*d) {
				p-=k;
				break;
			}
		}
		if(p*p+(p+k)*(p+k)>d*d) hd=1;
		if(hd) puts("Utkarsh");
		else puts("Ashish");
	}
	return 0;
} //