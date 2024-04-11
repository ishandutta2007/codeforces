#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=3e5+10;
int a[maxn],m,n,t_case;
int main(){
    scanf("%d",&t_case);
    while(t_case--){
        scanf("%d",&n);
        set<int>s;
        for(ri i=1;i<=n;++i)scanf("%d",a+i),s.insert(a[i]);
		for(ri i=1;i<=s.size();++i)printf("%d ",s.size());
		for(ri i=s.size()+1;i<=n;++i)printf("%d ",i);
		printf("\n");
    }
    return 0;
}