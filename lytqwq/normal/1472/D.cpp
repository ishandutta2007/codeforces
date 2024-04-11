#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,t,a[N];
long long int sum1,sum2;
int main(){
	scanf("%d",&t);
	while(t--){
		sum1=0;sum2=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]%2==0)sum2+=a[i];
			if(a[i]%2==1)sum1+=a[i];
		}
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--){
			if((n-i)%2==0)sum1-=a[i];
			else sum2-=a[i];
		}
		if(sum2>sum1)printf("Alice\n");
		else if(sum2==sum1)printf("Tie\n");
		else printf("Bob\n");
	}
}