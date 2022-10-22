#include<bits/stdc++.h>
using namespace std;
int t,w,h,n;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&w,&h,&n);
		int sum=1;
		while(w%2==0){
			w/=2;
			sum*=2;
		}
		while(h%2==0){
			h/=2;
			sum*=2;
		}
		if(sum>=n){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
}