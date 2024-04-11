#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,k,cn1[N],cn2[N];
char c1[N],c2[N];

int main() {
	T=read();
	while(T--) {
		n=read(), k=read();
		scanf("%s%s",c1+1,c2+1);
		sort(c1+1,c1+n+1), sort(c2+1,c2+n+1);
		rep(i,0,26) cn1[i]=cn2[i]=0;
 		rep(i,1,n) cn1[c1[i]-'a']++;
		rep(i,1,n) cn2[c2[i]-'a']++;
		int ans=1;
		rep(i,0,25) {
			if(i) cn1[i]=cn1[i]+cn1[i-1]/k*k;
			if(cn1[i]<cn2[i]) ans=0;
			else cn1[i]-=cn2[i];
		}
		if(ans==1) puts("Yes");
		else puts("No");
	}
	return 0;
} //