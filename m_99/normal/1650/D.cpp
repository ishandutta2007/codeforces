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
		
		deque<int> a(n);
		rep(i,n)cin>>a[i];
		vector<int> ans;
		for(int i=n;i>=1;i--){
			int cur = 0;
			while(a.back()!=i){
				a.push_back(a[0]);
				a.pop_front();
				cur++;
			}
			ans.push_back(cur);
			a.pop_back();
		}
		
		reverse(ans.begin(),ans.end());
		rep(i,ans.size()){
			if(i!=0)cout<<' ';
			cout<<ans[i];
		}
		cout<<endl;
		
	}
	
	return 0;
}