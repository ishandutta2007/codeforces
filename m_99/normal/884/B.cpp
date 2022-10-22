#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300000000



int main(){	
	
	int n,x;
	cin>>n>>x;
	
	int sum = 0;
	rep(i,n){
		int a;
		scanf("%d",&a);
		sum += a;
	}
	
	sum += n-1;
	if(sum==x)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	

    return 0;
}