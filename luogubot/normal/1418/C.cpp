#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+10,inf=1e9;
int n,a[N],f[N][2];
signed main(){
	int T=read();while(T--){
		For(i,1,n=read())a[i]=read();
		f[0][0]=0,f[0][1]=inf;
		For(i,1,n){
			f[i][0]=min(f[i-1][1],(i>=2)?(f[i-2][1]):inf);
			f[i][1]=min(f[i-1][0]+a[i],(i>=2)?(f[i-2][0]+a[i]+a[i-1]):inf);
		}cout<<min(f[n][0],f[n][1])<<endl;
	}
	return 0;
}