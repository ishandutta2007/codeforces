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
const int N=2e5+10;
int n,a[N],p[N];
signed main(){
	int T=read();while(T--){
		For(i,1,n=read())a[i]=read(),p[i]=0; 
		if(n==1)puts("-1");
		else{
			int fl=1;
			for(int i=1,j=1;i<=n;i=j+1){
				while(a[j+1]==a[i]&&j<n)j++;
				if(j==i)fl=0;
				else{
					For(k,i+1,j)p[k]=k-1;
					p[i]=j;
				}
			}if(!fl)puts("-1");
			else For(i,1,n)printf("%d%c",p[i]," \n"[i==n]);
		}
	}
	return 0;
}