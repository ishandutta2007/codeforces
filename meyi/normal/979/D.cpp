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
struct trie{
	trie *son[2];int val;
	inline trie(){son[0]=son[1]=NULL;val=INT_MAX;}
}*rt[maxn];
inline void insert(int k,int v){
	if(!rt[k])rt[k]=new trie();
	trie *now=rt[k];
	ckmin(now->val,v);
	for(ri j=16;~j;--j){
		ri nxt=(v>>j)&1;
		if(!now->son[nxt])now->son[nxt]=new trie();
		now=now->son[nxt];
		ckmin(now->val,v);
	}
}
inline void query(int k,int x,int y){
	if(!rt[k]){
		putchar('-'),putchar('1'),putchar(10);
		return;
	}
	trie *now=rt[k];
	for(ri j=16;~j;--j){
		ri nxt=((x>>j)&1)^1;
		if(now->son[nxt]&&now->son[nxt]->val<=y)now=now->son[nxt];
		else{
			nxt^=1;
			if(now->son[nxt]&&now->son[nxt]->val<=y)now=now->son[nxt];
			else{
				putchar('-'),putchar('1'),putchar(10);
				return;
			}
		}
	}
	qw(now->val),putchar(10);
}
vector<int>fac[maxn];
int n;
int main(){
	for(ri i=1;i<=100000;++i)
		for(ri j=i;j<=100000;j+=i)
			fac[j].push_back(i);
	n=qr();
	while(n--){
		ri op=qr(),x=qr();
		if(op&1){
			for(ri i:fac[x])insert(i,x);
		}
		else{
			ri y=qr(),z=qr();
			if(x%y||z<=x)putchar('-'),putchar('1'),putchar(10);
			else query(y,x,z-x);
		}
	}
	return 0;
}