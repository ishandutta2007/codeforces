#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;
const int N=2e5+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,a[N];

int main() {
	T=read();
	while(T--) {
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		int dep=1, num=1, lst=1;
		rep(i,3,n) {
			if(a[i]<a[i-1]) {
				if(num==1) dep++, num=i-lst, lst=i-1;
				num--;
			}
		}
		printf("%d\n",dep);
	}
	return 0;
}