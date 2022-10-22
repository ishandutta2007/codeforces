#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define ll long long
using namespace std;
inline ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
bool ST;
const int N=2e5+10,U=(1<<20)-1;
void print(int x){Rof(i,19,0)putchar((x>>i&1)+'0');}
struct Tree{//splitxormerge dep 
	#define ls(k) t[k].lc
	#define rs(k) t[k].rc
	int idx;
	struct node{
		int lc,rc,val,stal,star,tag;
		node(){lc=rc=val=stal=star=tag=0;}
	}t[N*30];
	void up(int k){
		t[k].stal=t[ls(k)].stal|t[rs(k)].stal;
		t[k].star=t[ls(k)].star|t[rs(k)].star;
		t[k].val=t[ls(k)].val+t[rs(k)].val;
	}
	void f_xor(int k,int x,int dep){
		if(x>>dep&1)swap(ls(k),rs(k));
		int L=t[k].stal,R=t[k].star;
		t[k].stal=(L&(x^U))|(R&x);//LR
		t[k].star=(L&x)|(R&(x^U));
		t[k].tag^=x; 
	}
	void down(int k,int dep){
		if(!t[k].tag)return;
		f_xor(ls(k),t[k].tag,dep-1),f_xor(rs(k),t[k].tag,dep-1);
		t[k].tag=0;
	}
	void ins(int &k,int x,int dep){
		if(!k)k=++idx;if(dep<0)return t[k].val=1,t[k].stal=x^U,t[k].star=x,void();
		x>>dep&1?ins(rs(k),x,dep-1):ins(ls(k),x,dep-1);
		up(k);
	}
	void split(int &k1,int &k2,int l,int r,int x,int y,int dep){
		if(!k1)return;
		if(x<=l&&r<=y)return k2=k1,k1=0,void();
		int m=l+r>>1;down(k1,dep),k2=++idx;
		if(x<=m)split(ls(k1),ls(k2),l,m,x,y,dep-1);
		if(y>m)split(rs(k1),rs(k2),m+1,r,x,y,dep-1);
		up(k1),up(k2);
	}
	int merge(int k1,int k2,int dep){
		if(!k1||!k2)return k1|k2;
		if(dep<0)return k1;
		down(k1,dep),down(k2,dep);
		t[k1].lc=merge(t[k1].lc,t[k2].lc,dep-1);
		t[k1].rc=merge(t[k1].rc,t[k2].rc,dep-1);
		up(k1);return k1;
	}
	void f_or(int &k,int x,int dep){
		if(!k||dep<0)return;
		if(!(x&t[k].stal&t[k].star))return f_xor(k,x&t[k].stal,dep);//0|1 -> 0^1
		down(k,dep);if(x>>dep&1){
			f_xor(ls(k),1<<dep,dep-1);
			t[k].rc=merge(t[k].lc,t[k].rc,dep-1),t[k].lc=0;
		}f_or(ls(k),x,dep-1),f_or(rs(k),x,dep-1);
		up(k);
	}
}T;
int n,m,rt;
bool ED;
signed main(){
//	fprintf(stderr,"%.2lf MB\n",abs(&ED-&ST)/1024.0/1024.0);
	n=read(),m=read();For(i,1,n)T.ins(rt,read(),19);
	while(m--){
		int op=read(),l=read(),r=read(),tmp=0;
		T.split(rt,tmp,0,U,l,r,19);
		if(op==4)printf("%d\n",T.t[tmp].val);
		else{
			int x=read();
			if(op==1)T.f_xor(tmp,U,19),T.f_or(tmp,x^U,19),T.f_xor(tmp,U,19);
			if(op==2)T.f_or(tmp,x,19);
			if(op==3)T.f_xor(tmp,x,19);
		}rt=T.merge(rt,tmp,19);
	}
	return 0;
}