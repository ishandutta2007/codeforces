#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<pair<int,int>> a(n);
		rep(i,n){
			cin>>a[i].first;
			a[i].second = i+1;
		}
		sort(a.begin(),a.end());
		
		cout<<a[0].second<<' '<<a.back().second<<endl;
		
		
		
	}
	
	return 0;
}