#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10,maxv=110;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
struct segment_tree{
	int ls,rs;
}t[maxn*100];
int cnt;
vector<int>st;
inline int new_node(){
	if(st.empty())return ++cnt;
	else{
		ri p=st.back();st.pop_back();
		t[p].ls=t[p].rs=0;
		return p;
	}
}
void insert(int &p,int l,int r,int k){
	if(!p)p=new_node();
	if(l==r)return;
	ri mid=l+r>>1;
	if(k<=mid)insert(t[p].ls,l,mid,k);
	else insert(t[p].rs,mid+1,r,k);
}
void merge(int &p1,int &p2){
	if(!p1||!p2){p1+=p2;return;}
	merge(t[p1].ls,t[p2].ls);
	merge(t[p1].rs,t[p2].rs);
	st.push_back(p2),p2=0;
}
void split(int &p1,int &p2,int l,int r,int ql,int qr){
	if(!p1)return;
	if(!p2)p2=new_node();
	if(ql<=l&&r<=qr){merge(p2,p1);return;}
	ri mid=l+r>>1;
	if(ql<=mid)split(t[p1].ls,t[p2].ls,l,mid,ql,qr);
	if(qr>mid)split(t[p1].rs,t[p2].rs,mid+1,r,ql,qr);
}
int ans[maxn],m,n,rt[maxv];
void query(int p,int l,int r,int k){
	if(!p)return;
	if(l==r){ans[l]=k;return;}
	ri mid=l+r>>1;
	query(t[p].ls,l,mid,k);
	query(t[p].rs,mid+1,r,k);
}
int main(){
	n=qr();
	for(ri i=1;i<=n;++i)insert(rt[qr()],1,n,i);
	m=qr();
	while(m--){
		ri l=qr(),r=qr(),x=qr(),y=qr();
		if(x==y)continue;
		ri tmp=0;
		split(rt[x],tmp,1,n,l,r);
		merge(rt[y],tmp);
	}
	for(ri i=1;i<=100;++i)query(rt[i],1,n,i);
	for(ri i=1;i<=n;++i)qw(ans[i]),putchar(32);
	return 0;
}