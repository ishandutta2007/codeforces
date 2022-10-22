#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int T,n,a[N],ans,cnt[N<<1],A[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int d=-80;d<=80;d++){
		for(int i=1;i<=n;i++)A[i]=a[i]-i*d;
		sort(A+1,A+n+1);
		for(int i=1,j=1;i<=n;i=j){
			while(A[j]==A[i]&&j<=n)j++;
			ans=max(ans,j-i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=max(i-1250,1);j<i;j++)if((a[i]-a[j])%(i-j)==0)ans=max(ans,(++cnt[(a[i]-a[j])/(i-j)+N])+1);
		for(int j=max(i-1250,1);j<i;j++)if((a[i]-a[j])%(i-j)==0)cnt[(a[i]-a[j])/(i-j)+N]--;
	}
	printf("%d\n",n-ans);
	return 0;
}