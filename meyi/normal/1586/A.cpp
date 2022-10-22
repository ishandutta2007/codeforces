#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=20010;
vector<int>pri;
bool vis[maxn];
inline void sieve(int siz){
	vis[1]=true;
	pri.clear();
	for(ri i=2;i<=siz;++i){
		if(!vis[i])pri.push_back(i);
		for(ri j:pri){
			if(i*j>siz)break;
			vis[i*j]=true;
			if(i%j==0)break;
		}
	}
}
int a[maxn],m,n,t_case;
int main(){
	sieve(20000);
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ri sum=0;
		for(ri i=1;i<=n;++i)scanf("%d",a+i),sum+=a[i];
		if(vis[sum]){
			printf("%d\n",n);
			for(ri i=1;i<=n;++i)printf("%d ",i);
		}
		else{
			printf("%d\n",n-1);
			ri pos=0;
			for(ri i=1;i<=n;++i)
				if(vis[sum-a[i]]){
					pos=i;
					break;
				}
			for(ri i=1;i<=n;++i)
				if(i!=pos)
					printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}