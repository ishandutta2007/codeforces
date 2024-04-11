#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){

	int n,k;
	cin>>n>>k;
	
	vector<pair<int,int>> a(n);
	rep(i,n){
		cin>>a[i].first;
		a[i].second = i;
	}
	
	sort(a.rbegin(),a.rend());
	
	int ans = 0;
	vector<int> inds;
	rep(i,k){
		ans += a[i].first;
		inds.push_back(a[i].second);
	}
	
	sort(inds.begin(),inds.end());
	cout<<ans<<endl;
	rep(i,inds.size()){
		if(i+1==inds.size()){
			if(i==0)cout<<n<<endl;
			else {
				cout<<' ';
				cout<<n-1-inds[i-1]<<endl;
			}
			break;
		}
		if(i==0)cout<<inds[i]+1;
		else{
			cout<<' ';
			cout<<inds[i]-inds[i-1];
		}
	}
	
	
	return 0;
}