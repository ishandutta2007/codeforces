#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int n,a[N],b[N],ac[N],bc[N],c[N],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),ac[a[i]]=i;
	for(int i=1;i<=n;i++) scanf("%d",&b[i]),bc[b[i]]=i;
	for(int i=1;i<=n;i++) c[(ac[i]+n-bc[i])%n]++;
	for(int i=0;i<=n;i++) ans=max(ans,c[i]);
	printf("%d",ans);
	return 0;
}