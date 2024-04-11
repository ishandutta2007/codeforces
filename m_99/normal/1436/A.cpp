#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

int main(){	
	
	int t;
	cin>>t;
	
	rep(_,t){
		int n,m;
		cin>>n>>m;
		
		vector<int> a(n);
		int sum = 0;
		rep(i,n){
			cin>>a[i];
			sum += a[i];
		}
		
		if(sum==m)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
    return 0;
}