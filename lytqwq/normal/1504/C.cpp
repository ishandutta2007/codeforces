#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int T,n;
char a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",a+1);
		if(n%2==1){
			printf("NO\n");
			continue;
		}
		if(a[1]=='0'||a[n]=='0'){
			printf("NO\n");
			continue;
		}
		int ans1=0,sum1=0,sum0=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='1'){
				ans1++;
			}
		}
		if(ans1%2==1){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=n;i++){
			if(a[i]=='1'){
				sum1++;
				if(sum1<=ans1/2){
					printf("(");
				}
				else{
					printf(")");
				}
			}
			if(a[i]=='0'){
				sum0++;
				if(sum0%2==0){
					printf("(");
				}
				else{
					printf(")");
				}
			}
		}
		printf("\n");
		sum1=sum0=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='1'){
				sum1++;
				if(sum1<=ans1/2){
					printf("(");
				}
				else{
					printf(")");
				}
			}
			if(a[i]=='0'){
				sum0++;
				if(sum0%2==1){
					printf("(");
				}
				else{
					printf(")");
				}
			}
		}
		printf("\n");
		
	}
	return 0;
}