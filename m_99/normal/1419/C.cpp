#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){

	int t;
	cin>>t;
	
	rep(_,t){
		int n,x;
		scanf("%d %d",&n,&x);
		
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		
		int cnt = 0;
		int sum = 0;
		
		rep(i,n){
			if(x==a[i])cnt++;
			sum += a[i];
		}
		
		if(cnt==n)printf("0\n");
		else{
			if(sum == x * n || cnt>=1){
				printf("1\n");
			}
			else{
				printf("2\n");
			}
		}
	}

	return 0;
}