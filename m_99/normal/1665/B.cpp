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
		
		map<int,int> mp;
		rep(i,n){
			int a;
			scanf("%d",&a);
			mp[a]++;
		}
		
		int m =0;
		for(auto a:mp)m = max(m,a.second);
		
		int ans = n-m;
		while(n!=m){
			m = min(n,m*2);
			ans++;
		}
		cout<<ans<<endl;
		
		
	}
		
	return 0;
}