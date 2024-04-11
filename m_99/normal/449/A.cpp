#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	long long n,m,k;
	cin>>n>>m>>k;
	
	long long ans = -1;
	
	for(long long i=1;i<=n;i++){

		long long a = i-1;
		long long b = k-a;
		
		if(a>=0&&a<n&&b>=0&&b<m)ans = max(ans,(n/(a+1)) * (m/(b+1)));
		if(b<0)ans = max(ans,(n/(a+1)) * m);
		long long t = i;
		i = n/(n/i);
		if(t!=i)i--;
	}
	
	cout<<ans<<endl;
	
    return 0;
}