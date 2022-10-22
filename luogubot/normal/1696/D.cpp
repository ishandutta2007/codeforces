#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
//#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2.5e5+10,inf=1e9;
int n,a[N],dp[N];
struct Tree{
	#define ls (k<<1)
	#define rs (k<<1|1)
	int t[N<<2];
	void build(int k,int l,int r){
		t[k]=inf;if(l==r)return;
		int m=l+r>>1;
		build(ls,l,m),build(rs,m+1,r);
		t[k]=min(t[ls],t[rs]);
	}
	void mdf(int k,int l,int r,int x,int v){
		if(l==r)return t[k]=v,void();
		int m=l+r>>1;
		if(x<=m)mdf(ls,l,m,x,v);
		else mdf(rs,m+1,r,x,v);
		t[k]=min(t[ls],t[rs]);
	}
	int ask(int k,int l,int r,int x,int y){
		if(x>y)return inf;
		if(x<=l&&r<=y)return t[k];
		int m=l+r>>1,ret=inf;
		if(x<=m)ret=min(ret,ask(ls,l,m,x,y));
		if(y>m)ret=min(ret,ask(rs,m+1,r,x,y));
		return ret;
	}
}T1,T2;
int stk1[N],tp1,stk2[N],tp2;
signed main(){
	int TTT=read();while(TTT--){
		n=read(),T1.build(1,1,n),T2.build(1,1,n),tp1=tp2=0;
		For(i,1,n)dp[i]=inf;dp[1]=0;For(i,1,n){
			a[i]=read();int TT1=tp1,TT2=tp2;
			while(tp1&&a[i]>a[stk1[tp1]])tp1--;while(tp2&&a[i]<a[stk2[tp2]])tp2--;
			if(i>1)dp[i]=min(T2.ask(1,1,n,stk1[tp1]+1,i-1),T1.ask(1,1,n,stk2[tp2]+1,i-1))+1;
			For(j,tp1+1,TT1)T1.mdf(1,1,n,stk1[j],inf);For(j,tp2+1,TT2)T2.mdf(1,1,n,stk2[j],inf);
			T1.mdf(1,1,n,i,dp[i]),T2.mdf(1,1,n,i,dp[i]);
			stk1[++tp1]=i,stk2[++tp2]=i;
		}printf("%d\n",dp[n]);
	}
	return 0;
}