#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define db double
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e3+10;
int n;db p[N][N],P[N],f[N];
int ok[N],st[N];
void addin(int j){
	For(i,1,n)if(!ok[i]){
		f[i]+=P[i]*p[i][j]*(f[j]+1.0);
		P[i]*=(1.0-p[i][j]);
	}
}
void print(){
	For(i,1,n)printf("f[%d] = %.10lf\n",i,f[i]);
}
signed main(){
	n=read();For(i,1,n)For(j,1,n)p[i][j]=0.01*read();
	For(i,1,n)P[i]=1,f[i]=0;ok[n]=st[n]=1,addin(n);
//	print();
	For(t,1,n-1){
		db mn=1e18;int id=-1;
		For(i,1,n)if(!ok[i]&&P[i]<1&&(f[i]+P[i])/(1.0-P[i])<mn)mn=(f[i]+P[i])/(1.0-P[i]),id=i;
		if(id==-1)break;
		ok[id]=1,f[id]=(f[id]+P[id])/(1.0-P[id]),addin(id);
//		print();
	}printf("%.10lf\n",f[1]);
	return 0;
}