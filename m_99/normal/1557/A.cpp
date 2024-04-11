#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		vector<double> a(n);
		rep(i,n){
			int t;
			scanf("%d",&t);
			a[i] = t;
		}
		sort(a.begin(),a.end());
		
		double ans = a.back();
		a.pop_back();
		
		double sum = 0.0;
		rep(i,n-1)sum += a[i];
		sum /= n-1;
		ans += sum;
		
		cout<<fixed<<setprecision(10)<<ans<<endl;
		
		
		
		
		
	}
	
	return 0;
}