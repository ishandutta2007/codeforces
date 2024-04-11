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
const int N=1e5+10;
int f[2][N],n,q,cnt;
signed main(){
	n=read(),q=read();while(q--){
		int x=read()-1,y=read();
		if(f[x][y]){f[x][y]=0;For(i,y-1,y+1)if(f[x^1][i])cnt--;}
		else {f[x][y]=1;For(i,y-1,y+1)if(f[x^1][i])cnt++;}
		puts(cnt?"No":"Yes");
	}
	return 0;
}