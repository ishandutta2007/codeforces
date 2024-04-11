#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		
		vector<int> a(n);
		rep(i,n)cin>>a[i];
		
		sort(a.begin(),a.end());
		vector<int> t;
		rep(i,k){
			t.push_back(a.back());
			a.pop_back();
		}
		reverse(t.begin(),t.end());
		int ans = 0;
		while(a.size()!=0){
			int v = a.back();
			a.pop_back();
			if(t.size()!=0){
				v /= t.back();
				t.pop_back();
			}
			ans += v;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}