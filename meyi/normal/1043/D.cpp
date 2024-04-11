#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxm=11,maxn=1e5+10;
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
int a[maxn][maxm],m,n,pos[maxn][maxm];
ll ans;
int main(){
	n=qr(),m=qr();
	for(ri i=1;i<=m;++i)
		for(ri j=1;j<=n;++j)
			pos[a[j][i]=qr()][i]=j;
	for(ri i=1;i<=n;){
		ri j=i;
		while(j<n){
			for(ri k=2;k<=m;++k)
				if(pos[a[j][1]][k]==n||a[pos[a[j][1]][k]+1][k]!=a[j+1][1])
					goto skip;
			++j;
		}
		skip:;
		ans+=1ll*(j-i+1)*(j-i+2)/2;
		i=j+1;
	}
	printf("%lld",ans);
	return 0;
}