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
const int N=100+10;
int f[N][N*N],n,a[N],b[N],all;
//f[i][j]:isum a=j sum b 
inline void gmax(int &a,int b){(a<b)&&(a=b);}
signed main(){
	n=read();For(i,1,n)a[i]=read(),b[i]=read(),all+=b[i];
	memset(f,-1,sizeof f);f[0][0]=0;
	For(i,1,n){
		Rof(j,i-1,0)For(k,0,j*100)if(f[j][k]!=-1){
			gmax(f[j+1][k+a[i]],f[j][k]+b[i]);
		}
	}For(i,1,n){
		int ans=0;
		For(j,0,i*100)if(f[i][j]!=-1){
			gmax(ans,min(j*2,all+f[i][j]));
		}printf("%.2lf ",1.0*ans/2);
	}
	return 0;
}