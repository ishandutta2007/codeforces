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
bool ST;
const int N=1e5+10;
int n,m;
struct DSU{
	int fa[N],ok[N];
	void init(){For(i,1,n)fa[i]=i,ok[i]=0;}
	int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
	void merge(int u,int v){fa[get(u)]=get(v);}
	void g(int u){ok[get(u)]=1;}
}A[30],B[30];
int U[N],V[N],k;
bool ED;
signed main(){
//	printf("%.2lf MB\n",abs(&ED-&ST)/1024.0/1024.0);
	n=read(),m=read();For(j,0,29)A[j].init(),B[j].init();
	For(i,1,m){
		int u=read(),v=read(),w=read();
		Rof(j,29,0)if(w>>j&1){
			A[j].merge(u,v);
			if(j&&(w&1))B[j].merge(u,v);
		}if(!(w&1))k++,U[k]=u,V[k]=v;
	}For(i,1,k)For(j,1,29)if(B[j].get(U[i])!=B[j].get(V[i]))
		B[j].g(U[i]),B[j].g(V[i]);
	int q=read();while(q--){
		int u=read(),v=read(),fl=0;
		For(j,0,29)fl|=A[j].get(u)==A[j].get(v);
		if(fl){puts("0");continue;}
		For(j,0,29)fl|=B[j].ok[B[j].get(u)];
		puts(fl?"1":"2");
	}
	return 0;
}//dasdsa