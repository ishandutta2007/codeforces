#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int h[maxn],k,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		for(ri i=1;i<=n;++i)scanf("%d",h+i);
		while(k){
			for(ri i=1;i<n;++i)
				if(h[i]<h[i+1]){
					ri d=h[i+1];
					if(i>1)ckmin(d,h[i-1]+1);
					if(d-h[i]>=k)k=0,printf("%d\n",i);
					else k-=d-h[i],h[i]=d;
					goto skip;
				}
			puts("-1");
			break;
			skip:;
		}
	}
	return 0;
}