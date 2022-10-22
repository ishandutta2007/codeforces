#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
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
int cnt,lst,m,n,q,rt[maxn];
vector<int>pos[maxn];
struct node{int ls,rs,sum;}t[maxn<<6];
void insert(int &p,int l,int r,int k){
	t[++cnt]=t[p];
	p=cnt;
	++t[p].sum;
	if(l==r)return;
	ri mid=l+r>>1;
	k<=mid?insert(t[p].ls,l,mid,k):insert(t[p].rs,mid+1,r,k);
}
int query(int p1,int p2,int l,int r,int k){
	if(l==r)return t[p2].sum-t[p1].sum;
	ri mid=l+r>>1;
	return k<=mid?query(t[p1].ls,t[p2].ls,l,mid,k):t[t[p2].ls].sum-t[t[p1].ls].sum+query(t[p1].rs,t[p2].rs,mid+1,r,k);
}
int main(){
	n=qr(),m=qr();
	for(ri i=1,x;i<=n;++i){
		pos[x=qr()].push_back(i);
		rt[i]=rt[i-1];
		insert(rt[i],0,n,pos[x].size()>m?pos[x][pos[x].size()-m-1]:0);
	}
	q=qr();
	while(q--){
		ri l=(qr()+lst)%n+1,r=(qr()+lst)%n+1;
		if(l>r)swap(l,r);
		qw(lst=query(rt[l-1],rt[r],0,n,l-1)),putchar(10);
	}
	return 0;
}