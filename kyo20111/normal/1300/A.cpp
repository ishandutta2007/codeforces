#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, a[111];
int main(){
	scanf("%d",&t);
	while(t--){
		int ans = 0, sum = 0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
			if(a[i] == 0) ans++, a[i]++;
			sum += a[i];
		}
		printf("%d\n",ans+(sum == 0));
	}
}