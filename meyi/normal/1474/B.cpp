#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
vector<int>pri;
bool vis[maxn];
inline void sieve(int siz){
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
int n,t_case;
int main(){
	sieve(200000);
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ri ans1,ans2;
		for(ans1=1+n;vis[ans1];++ans1);
		for(ans2=ans1+n;vis[ans2];++ans2);
		printf("%lld\n",1ll*ans1*ans2);
	}
	return 0;
}