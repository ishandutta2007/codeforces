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
int n,a,b,c[N];
signed main(){
	int T=read();while(T--){
		n=read(),a=read(),b=read();
		if(abs(a-b)>1||a+b>n-2){puts("-1");continue;}
		int L=1,R=n,fl=a==b+1;For(i,1,n){
			if(fl)c[i]=L++;
			else c[i]=R--;
			if(a+b>=i)fl^=1;
		}For(i,1,n)printf("%d ",c[i]);puts("");
	}
	return 0;
}