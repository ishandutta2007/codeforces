#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
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
map<int,int>cnt[maxn];
int ans,m,n;
int main(){
	n=qr(),m=qr();
	while(m--){
		ri len=1,x=qr(),y=qr(),z=qr();
		auto it=cnt[x].lower_bound(z);
		if(it!=cnt[x].begin()){
			--it;
			len=it->second+1;
		}
		ckmax(ans,len);
		it=cnt[y].upper_bound(z);
		if(it!=cnt[y].begin()&&prev(it)->second>=len)continue;
		while(it!=cnt[y].end()&&it->second<=len)it=cnt[y].erase(it);
		cnt[y][z]=len;
	}
	printf("%d",ans);
	return 0;
}