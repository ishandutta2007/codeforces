#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=5009;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,h[N],s[N],f[N],g[N];

int main() {
	n=read();
	rep(i,1,n) h[i]=read(), s[i]=s[i-1]+h[i];
	memset(f,0x3f,sizeof(f));
	f[0]=0; 
	rep(i,1,n) {
		per(j,i-1,0) {
			if(s[i]-s[j]>=g[j]&&f[i]>f[j]+i-j-1) {
				f[i]=f[j]+i-j-1;
				g[i]=s[i]-s[j];
			}
		}
	}
	printf("%d\n",f[n]);
	return 0;
}