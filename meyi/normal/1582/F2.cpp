#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxa=1<<13,maxn=1e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],ans,n,r[maxn];
vector<int>to[maxa];
bool vis[maxn];
int main(){
	scanf("%d",&n);
	for(ri i=1;i<maxa;++i)r[i]=maxa-1,to[i]={0};
	vis[0]=true;
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		for(auto j:to[a[i]]){
			ri k=a[i]^j;
			vis[k]=true;
			while(r[k]>a[i])to[r[k]--].push_back(k);
		}
		to[a[i]]={};
	}
	for(ri i=0;i<maxa;++i)ans+=vis[i];
	printf("%d\n",ans);
	for(ri i=0;i<maxa;++i)if(vis[i])printf("%d ",i);
	return 0;
}