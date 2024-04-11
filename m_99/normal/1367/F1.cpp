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
		
		vector<int> a(n);
		rep(i,n){
			cin>>a[i];
		}
		{
			vector<int> t = a;
			sort(t.begin(),t.end());
			rep(i,n){
				a[i] = distance(t.begin(),lower_bound(t.begin(),t.end(),a[i]));
			}
		}
		
		int ans = 0;
		
		rep(i,n){
			int c = i;
			rep(j,n){
				if(a[j]==c)c++;
			}
			ans = max(ans,c-i);
		}
		ans = n-ans;
		cout<<ans<<endl;
	}
		
	
	return 0;
}