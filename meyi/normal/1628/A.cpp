#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
vector<int>pos[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=0;i<=n;++i)vector<int>().swap(pos[i]);
		for(ri i=1;i<=n;++i)scanf("%d",a+i),pos[a[i]].push_back(i);
		vector<int>ans;
		for(ri i=1;i<=n;){
			ri nxt=i;
			for(ri mex=0;;++mex){
				auto it=lower_bound(pos[mex].begin(),pos[mex].end(),i);
				if(it==pos[mex].end()){ans.push_back(mex);break;}
				else ckmax(nxt,*it);
			}
			i=nxt+1;
		}
		printf("%d\n",ans.size());
		for(ri i:ans)printf("%d ",i);
		printf("\n");
	}
	return 0;
}