#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001


int main(){	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		sort(a.begin(),a.end());
		
		long long ans = Inf64;
		for(int i=1;i<n-1;i++){
			ans = min(ans,(long long)abs(a[i]-a[i-1]) + abs(a[i]-a[i+1]));
		}
		cout<<ans<<endl;
		
		
	}
	
	return 0;
	
}