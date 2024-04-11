#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000


int main(){	
	
	int t;
	cin>>t;
	rep(_,t){
		int n;
		cin>>n;
		vector<int> a(n);
		rep(i,n)cin>>a[i];
		while(a.back()==0)a.pop_back();
		while(a[0]==0)a.erase(a.begin());
		int ans = a.size();
		rep(i,a.size()){
			if(a[i])ans--;
		}
		
		cout<<ans<<endl;
		
	}
		
    return 0;
}