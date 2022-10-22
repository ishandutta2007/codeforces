#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=5010;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],ans1,ans2,ans3,b[maxn],id[maxn],lim1,lim2,lim3,n,rk[maxn];
inline int calc(int k){return b[k]-b[k+1];}
struct cmp{inline bool operator()(int x,int y)const{return calc(x)!=calc(y)?calc(x)>calc(y):x<y;}};
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i),id[i]=i;
	stable_sort(id+1,id+n+1,[&](int x,int y){return a[x]>a[y];});
	for(ri i=1;i<=n;++i)b[i]=a[id[i]],rk[id[i]]=i;
	for(ri i=1;i+1<n;++i)
		if(calc(i)>=ans1){
			set<int,cmp>s;
			for(ri j=i+1,l=j+1,r=j+1;j<n;++j){
				ri x=i,y=j-i;
				if(x<y)swap(x,y);
				if((calc(i)>ans1||calc(j)>=ans2)&&x<=y<<1){
					while(r<=n&&r-j<=y<<1)s.insert(r++);
					while(l<=n&&(l<=j||l-j<<1<x))s.erase(l++);
					if(s.size()){
						if(ckmax(ans1,calc(i)))ans2=calc(j),ans3=calc(*s.begin()),lim1=i,lim2=j,lim3=*s.begin();
						else if(ckmax(ans2,calc(j)))ans3=calc(*s.begin()),lim1=i,lim2=j,lim3=*s.begin();
						else if(ckmax(ans3,calc(*s.begin())))lim1=i,lim2=j,lim3=*s.begin();
					}
				}
			}
		}
	for(ri i=1;i<=n;++i)printf("%d ",rk[i]<=lim1?1:rk[i]<=lim2?2:rk[i]<=lim3?3:-1);
	return 0;
}