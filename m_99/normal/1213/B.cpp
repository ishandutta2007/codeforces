#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	//_t = 1;
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		reverse(a.begin(),a.end());
		int ans = 0;
		int last = Inf;
		
		rep(i,n){
			if(a[i]>last)ans++;
			last = min(last,a[i]);
		}
		
		cout<<ans<<endl;
		
		
	}
	
	return 0;
}