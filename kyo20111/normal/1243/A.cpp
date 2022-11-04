#include<bits/stdc++.h>
using namespace std;
int t,n,a[1010];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		a[n+1] = 0;
		sort(a+1, a+1+n, greater<int>());
		for(int i=1;i<=n+1;i++){
			if(a[i] < i){
				printf("%d\n",i-1);
				break;
			}
		}

	}
}