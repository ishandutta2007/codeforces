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
const int N=2e5+10;
char s[N],f[N];int n,q,fl;
struct Tree{
	#define ls (k<<1)
	#define rs (k<<1|1)
	int t[N<<2],tag[N<<2];
	void up(int k){t[k]=t[ls]+t[rs];}
	void F(int k,int v,int l,int r){
		if(v==1)t[k]=r-l+1,tag[k]=v;
		if(v==0)t[k]=0,tag[k]=0;
	}
	void down(int k,int l,int r){
		int m=l+r>>1;F(ls,tag[k],l,m),F(rs,tag[k],m+1,r);
		tag[k]=-1;
	}
	void build(int k,int l,int r){
		tag[k]=-1;
		if(l==r)return t[k]=(f[l]=='1'),void();
		int m=l+r>>1;
		build(ls,l,m),build(rs,m+1,r),up(k);
	}
	int sum(int k,int l,int r,int x,int y){
		if(x<=l&&r<=y)return t[k];
		int m=l+r>>1;down(k,l,r);
		int ret=0;
		if(x<=m)ret+=sum(ls,l,m,x,y);
		if(y>m)ret+=sum(rs,m+1,r,x,y);
		up(k);return ret;
	}
	void mdf(int k,int l,int r,int x,int y,int v){
		if(x<=l&&r<=y)return F(k,v,l,r);
		int m=l+r>>1;down(k,l,r);
		if(x<=m)mdf(ls,l,m,x,y,v);
		if(y>m)mdf(rs,m+1,r,x,y,v);
		up(k);	
	}
	void check(int k,int l,int r){
		if(l==r)return fl&=t[k]==(s[l]-'0'),void();
		int m=l+r>>1;down(k,l,r);
		check(ls,l,m),check(rs,m+1,r);
		up(k);
	}
	void print(int k,int l,int r){
		if(l==r)return putchar(t[k]+'0'),void();
		int m=l+r>>1;down(k,l,r);
		print(ls,l,m),print(rs,m+1,r);
		up(k);
	}
}T;int L[N],R[N];
signed main(){
	int TTT=read();while(TTT--){
		n=read(),q=read();scanf("%s%s",s+1,f+1),fl=1;
		For(i,1,q)L[i]=read(),R[i]=read();T.build(1,1,n);
//		T.print(1,1,n);puts("");
		Rof(i,q,1){
			int l=L[i],r=R[i],x=T.sum(1,1,n,l,r); 
			if(x*2==r-l+1){fl=0;break;}
			T.mdf(1,1,n,l,r,x*2>=r-l+1);
//			T.print(1,1,n);puts("");
		}T.check(1,1,n);puts(fl?"Yes":"No");
	}
	return 0;
}