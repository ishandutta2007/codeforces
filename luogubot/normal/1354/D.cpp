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
const int N=1e6+10;
struct Tree{
	#define ls (k<<1)
	#define rs (k<<1|1)
	int t[N<<2];
	void add(int k,int l,int r,int x){
		if(l==r)return t[k]++,void();
		int m=l+r>>1;
		x<=m?add(ls,l,m,x):add(rs,m+1,r,x);
		t[k]=t[ls]+t[rs];
	}
	void del(int k,int l,int r,int x){
		if(t[k]<x)return;
		if(l==r)return t[k]--,void();
		int m=l+r>>1;
		if(t[ls]>=x)del(ls,l,m,x);
		else del(rs,m+1,r,x-t[ls]);
		t[k]=t[ls]+t[rs];
	}
	void print(int k,int l,int r){
		assert(t[k]);
		if(l==r)return cout<<l<<endl,void();
		int m=l+r>>1;
		if(t[ls])print(ls,l,m);
		else print(rs,m+1,r);
	}
}T;
int n,q;
bool ED;
signed main(){
	n=read(),q=read();
	For(i,1,n)T.add(1,1,n,read());
	while(q--){
		int x=read();
		if(x<0)T.del(1,1,n,-x);
		else T.add(1,1,n,x);
	}if(T.t[1]==0)puts("0");
	else T.print(1,1,n);
	return 0;
}