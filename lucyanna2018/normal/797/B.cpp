#include<bits/stdc++.h>
using namespace std;
int main(){
	int mx = -99999, mn = 99999,n,x;
	scanf("%d",&n);
	int sum=0;
	for(int i=0; i<n; i++){
		scanf("%d",&x);
		if(x > 0) sum += x;
		if(x > 0 && x%2!=0)mn = min(mn, x);
		if(x < 0 && x%2!=0)mx = max(mx, x);
	}
	if(sum % 2 == 0){
		sum = max(sum - mn, sum + mx);
	}
	printf("%d\n",sum);
	return 0;
}