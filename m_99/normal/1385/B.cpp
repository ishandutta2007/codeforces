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
		
		set<int> used;
		vector<int> ans;
		rep(i,2*n){
			int a;
			cin>>a;
			if(used.count(a))continue;
			used.insert(a);
			ans.push_back(a);
		}
		
		rep(i,n){
			if(i!=0)cout<<' ';
			cout<<ans[i];
		}
		cout<<endl;
	}
	
	return 0;
}