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
		vector<long long> a(n);
		rep(i,n)cin>>a[i];
		sort(a.begin(),a.end());
		
		long long ans = (a.back() + 2)/3;
		set<int> s;
		rep(i,n){
			s.insert(a[i]%3);
		}
		if(a.back()%3==0){
			if(s.size()!=1)ans++;
		}
		else if(a.back()%3==1){
			
			if(s.count(2)){
				if(binary_search(a.begin(),a.end(),1)||binary_search(a.begin(),a.end(),a.back()-1))ans++;
			}
		}
		else{
			if(s.count(1))ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}