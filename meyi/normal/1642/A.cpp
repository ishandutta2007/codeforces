#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int t_case,x[3],y[3];
int main(){
    scanf("%d",&t_case);
    while(t_case--){
    	bool f=0;
        for(ri i=0;i<3;++i)scanf("%d%d",x+i,y+i);
		for(ri i=0;i<3;++i)
			for(ri j=0;j<i;++j)
				if(y[i]==y[j]&&y[i^j^3]<y[i])
					f=1,printf("%d\n",abs(x[i]-x[j]));
		if(!f)puts("0");
    }
    return 0;
}