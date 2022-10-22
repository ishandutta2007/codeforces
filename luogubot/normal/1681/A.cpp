#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int n;
signed main(){
	int T=read();while(T--){
		int a=0,b=0;For(i,1,n=read())a=max(a,read());For(i,1,n=read())b=max(b,read());
		puts(b>a?"Bob":"Alice"),puts(a>b?"Alice":"Bob");
	}
	return 0;
}