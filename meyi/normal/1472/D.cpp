#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
ll sum[2];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		sort(a+1,a+n+1,greater<int>());
		sum[0]=sum[1];
		for(ri i=1;i<=n;++i)
			if((i&1)!=(a[i]&1))
				sum[i&1]+=a[i];
		if(sum[1]>sum[0])puts("Alice");
		else if(sum[0]>sum[1])puts("Bob");
		else puts("Tie");
	}
	return 0;
}