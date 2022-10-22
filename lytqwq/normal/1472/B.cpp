#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int sum1=0,sum2=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(x==1)sum1++;
			else sum2++;
		}
		if((sum2%2==0&&sum1%2==0)||(sum2%2==1&&sum1>=2&&sum1%2==0)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
}