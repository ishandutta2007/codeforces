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
const int N=1e3+10,p=1e9+7;
int n,f[N][N],ans;
signed main(){
	n=read(),f[0][0]=1;For(i,1,n)For(j,0,i){
		f[i][j]=((i?f[i-1][j]:0)+(j?f[i][j-1]:0))%p;
//		printf("f[%d][%d] = %lld\n",i,j,f[i][j]);
		if(i+j&1)(ans+=f[i][j])%=p;
	}cout<<ans<<endl;
	return 0;
}