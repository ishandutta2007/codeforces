#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n,k;
		scanf("%lld %lld",&n,&k);
		
		long long ans;
		if(n>k){
			if(n%k==0)ans = 1;
			else ans = 2;
		}
		else{
			ans	= k/n;
			if(k%n!=0)ans++;
		}
		
		//cout<<k%n<<endl;
		
		printf("%lld\n",ans);
		
		
	}
	
    return 0;
}