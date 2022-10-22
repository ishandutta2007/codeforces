#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300


int main(){	
	
	int _t;
	cin>>_t;
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		
		vector<int> a(n);
		set<int> S;
		rep(i,n){
			cin>>a[i];
			S.insert(a[i]);
		}
		
		int m = S.size();
		int ans = 1;
		m -= k;
		if(m>0){
			if(k==1){
				cout<<-1<<endl;
				continue;
			}
			k--;
			ans += (m+k-1)/k;
		}
		cout<<ans<<endl;
		
	}
	
    return 0;
}