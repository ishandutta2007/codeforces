#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int a[maxn],ans,m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ans=0;
		for(ri i=1;i<=n;++i)scanf("%d",a+i),ans+=((a[i]==1)||(a[i]==3));
		printf("%d\n",ans);
	}
	return 0;
}