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
bool ST;
const int N=3e5+10,LG=32;
int ans,n;
struct Trie{
	int c[N*LG][2],val[N*LG][2][2],idx;
	void init(){idx=0,c[0][0]=c[0][1]=0;}
	inline void cl(int r){For(i,0,1)c[r][i]=0;For(i,0,1)For(j,0,1)val[r][i][j]=0;} 
	void ins(int x,int a,int b){
		int s=0,r=0;Rof(i,31,0){
			int u=x>>i&1,A=a>>i&1,B=b>>i&1;
			if(A==0&&B==0)s=max(s,val[r][0][1]);
			if(A==0&&B==1)s=max(s,val[r][1][1]);
			if(A==1&&B==0)s=max(s,val[r][0][0]);
			if(A==1&&B==1)s=max(s,val[r][1][0]);
			if(!c[r][u])c[r][u]=++idx,cl(idx);
			r=c[r][u];
		}s++,r=0;Rof(i,31,0){
			int u=x>>i&1,A=a>>i&1,B=b>>i&1;
			val[r][A][B]=max(val[r][A][B],s);r=c[r][u];
		}ans=max(ans,s);
	}
}T;
int a[N],f[N];
bool ED;
signed main(){
//	printf("%.2lf MB\n",abs(&ED-&ST)/1024.0/1024.0);
	int Tc=read();while(Tc--){
		T.init(),ans=0,n=read();For(i,0,n-1)a[i]=read(),T.ins(a[i]^i,a[i],i);
		printf("%d\n",ans);
	}
	return 0;
}