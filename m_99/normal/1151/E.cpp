#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

long long get(long long i){
	return i * (i+1) /2;
}

int main(){
	
	long long n;
	cin>>n;
	
	vector<int> a(n);
	rep(i,n){
		scanf("%d",&a[i]);
		a[i]--;
	}
	
	long long ans = 0LL;

	for(long long i=0;i<n;i++){
		if(i==0){
			ans += (a[i]+1) * (n-a[i]);
		}
		else{
			long long x = a[i],y = a[i-1];
			if(x<y){
				ans += (y-x) * (a[i]+1);
			}
			else{
				ans += (x-y) * (n-a[i]);
			}
		}
		//cout<<ans<<endl;
	}
	
	cout<<ans<<endl;
	
    return 0;
}