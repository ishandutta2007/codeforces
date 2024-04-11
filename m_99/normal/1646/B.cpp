#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000003


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<long long> a(n);
		rep(i,n)scanf("%lld",&a[i]);
		sort(a.begin(),a.end());
		long long x = a[0];
		long long y =0;
		bool f = false;
		for(int i=1;i<n;i++){
			if(i>=n-i)break;
			x += a[i];
			y += a[n-i];
			if(x<y)f = true;
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
			
		
	}
	
	return 0;
}