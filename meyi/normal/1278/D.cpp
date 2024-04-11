#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=5e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
int cnt,id[maxn],l[maxn],m,n,r[maxn];
struct dsu{
	int fa[maxn],siz[maxn];
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			++cnt;
			if(siz[x]>siz[y])swap(x,y);
			fa[x]=y,siz[y]+=siz[x];
		}
		else puts("NO"),exit(0);
	}
}d;
struct cmp{inline bool operator()(int x,int y){return r[x]<r[y];}};
multiset<int,cmp>s;
int main(){
	n=qr();
	for(ri i=1;i<=n;++i)d.fa[i]=id[i]=i,l[i]=qr(),r[i]=qr(),d.siz[i]=1;
	sort(id+1,id+n+1,[&](int x,int y){return l[x]!=l[y]?l[x]<l[y]:r[x]>r[y];});
	for(ri ii=1,j=1;ii<=n;++ii){
		ri i=id[ii];
		while(l[i]!=l[id[j]])s.insert(id[j++]);
		auto it=s.upper_bound(i);
		while(it!=s.begin()){
			--it;
			if(r[*it]<l[i])break;
			d.merge(i,*it);
		}
	}
	puts(cnt==n-1?"YES":"NO");
	return 0;
}