#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct segment_tree{
	int ls,rs,sum,tag;
}t[maxn*50];
int cnt,rt;
inline void push_up(int p){
	t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;
}
inline void add_tag(int &p,int l,int r,bool v){
	if(!p)p=++cnt;
	t[p].sum=(v?r-l+1:0);
	t[p].tag=v;
}
inline void push_down(int p,int l,int r){
	if(t[p].tag==-1)return;
	ri mid=l+r>>1;
	add_tag(t[p].ls,l,mid,t[p].tag);
	add_tag(t[p].rs,mid+1,r,t[p].tag);
	t[p].tag=-1;
}
void modify(int &p,int l,int r,int ql,int qr,bool v){
	if(!p)p=++cnt,t[p].tag=-1;
	if(l>qr||ql>r)return;
	if(ql<=l&&r<=qr){
		add_tag(p,l,r,v);
		return;
	}
	push_down(p,l,r);
	ri mid=l+r>>1;
	modify(t[p].ls,l,mid,ql,qr,v);
	modify(t[p].rs,mid+1,r,ql,qr,v);
	push_up(p);
}
int query(int p,int l,int r,int ql,int qr){
	if(!p)return 0;
	if(l>qr||ql>r)return 0;
	if(ql<=l&&r<=qr)return t[p].sum;
	push_down(p,l,r);
	ri mid=l+r>>1;
	return query(t[p].ls,l,mid,ql,qr)+query(t[p].rs,mid+1,r,ql,qr);
}
int n,q;
int main(){
	scanf("%d%d",&n,&q);
	modify(rt,1,n,1,n,1);
	while(q--){
		ri l,r,v;
		scanf("%d%d%d",&l,&r,&v);
		modify(rt,1,n,l,r,v-1);
		printf("%d\n",query(rt,1,n,1,n));
	}
	return 0;
}