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
		cin>>n;
		int l,r;
		cin>>l>>r;
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
		}
		sort(a.begin(),a.end());
		long long ans = 0LL;
		rep(i,n){
			int d = distance(lower_bound(a.begin(),a.end(),l-a[i]),upper_bound(a.begin(),a.end(),r-a[i]));
			ans += d;
		}
		rep(i,n){
			if(a[i]*2>=l&&a[i]*2<=r)ans--;
		}
		ans /= 2;
		
		cout<<ans<<endl;
	
	}
	return 0;
}