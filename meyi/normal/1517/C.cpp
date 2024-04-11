#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=510;
int a[maxn],ans[maxn][maxn],len[maxn],m,n,t_case;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	memset(ans,0,sizeof ans);
	memset(len,0,sizeof len);
	for(ri i=1;i<=n;++i){
		ri tmp=a[i];
		len[i]=i-1;
		for(ri j=i;j>1&&tmp;--j)
			while(len[j]<=min(len[j-1],n-1)&&tmp)
				ans[++len[j]][j]=a[i],--tmp;
		for(ri j=1;tmp;++j)
			while(len[j]<n&&tmp)
				ans[++len[j]][j]=a[i],--tmp;
	}
	for(ri i=1;i<=n;puts(""),++i)
		for(ri j=1;j<=i;++j)
			printf("%d ",ans[i][j]);
	return 0;
}