#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
int a[maxn],m,n,k,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		sort(a+1,a+n+1);
		m=-1;
		if(a[1]!=0)m=0;
		else
			for(ri i=2;i<=n;++i)
				if(a[i]!=a[i-1]+1){
					m=a[i-1]+1;
					break;
				}
		if(!~m)printf("%d\n",n+k);
		else if(k){
			int tmp=(m+a[n]+1)>>1;
			bool flag=true;
			for(ri i=1;i<=n;++i)
				if(a[i]==tmp){
					flag=false;
					break;
				}
			printf("%d\n",n+flag);
		}
		else printf("%d\n",n);
	}
}