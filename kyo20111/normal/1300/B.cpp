#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, a[200200];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) scanf("%d",a+i);
		sort(a+1, a+1+2*n);
		printf("%d\n",a[n+1]-a[n]);
	}
}