#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=25e4+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[510][510],cnt,k,n,sum[maxn],tot[maxn];
inline int idx(int x,int y){return (x-1)*n+y;}
int main(){
	scanf("%d%d",&n,&k);
	if(n==1)return putchar(48),0;
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=n;++j){
			scanf("%d",&a[i][j]);
			if(!sum[a[i][j]]++)++cnt;
		}
	if(cnt<=k)return printf("%d",k-cnt),0;
	for(ri i=1;i<=n;++i){
		clear(tot,n*n);
		for(ri l=1,r=1,x=0;r<=n-i+1;++r){
			// (1+l-1,i+l-1) (1+r-1,i+r-1)
			for(ri j=1+l-1;j<=1+r-1;++j)
				if(++tot[a[j][i+r-1]]==sum[a[j][i+r-1]])
					++x;
			for(ri j=i+l-1;j<i+r-1;++j)
				if(++tot[a[1+r-1][j]]==sum[a[1+r-1][j]])
					++x;
			while(x>cnt-k+1){
				for(ri j=1+l-1;j<=1+r-1;++j)
					if(tot[a[j][i+l-1]]--==sum[a[j][i+l-1]])
						--x;
				for(ri j=i+l-1+1;j<=i+r-1;++j)
					if(tot[a[1+l-1][j]]--==sum[a[1+l-1][j]])
						--x;
				++l;
			}
			if(x==cnt-k||x==cnt-k+1)return putchar(49),0;
		}
	}
	for(ri i=2;i<=n;++i){
		clear(tot,n*n);
		for(ri l=1,r=1,x=0;r<=n-i+1;++r){
			// (i+l-1,1+l-1) (i+r-1,1+r-1)
			for(ri j=i+l-1;j<=i+r-1;++j)
				if(++tot[a[j][1+r-1]]==sum[a[j][1+r-1]])
					++x;
			for(ri j=1+l-1;j<1+r-1;++j)
				if(++tot[a[i+r-1][j]]==sum[a[i+r-1][j]])
					++x;
			while(x>cnt-k+1){
				for(ri j=i+l-1;j<=i+r-1;++j)
					if(tot[a[j][1+l-1]]--==sum[a[j][1+l-1]])
						--x;
				for(ri j=1+l-1+1;j<=1+r-1;++j)
					if(tot[a[i+l-1][j]]--==sum[a[i+l-1][j]])
						--x;
				++l;
			}
			if(x==cnt-k||x==cnt-k+1)return putchar(49),0;
		}
	}
	putchar(50);
	return 0;
}