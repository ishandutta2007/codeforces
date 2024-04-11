#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 100000000000000000


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<long long> a(n),b(n);
		rep(i,n)scanf("%lld",&a[i]);
		rep(i,n)scanf("%lld",&b[i]);
		
		vector<int> type;
		vector<long long> cost;
		type.push_back(5);
		cost.push_back(abs(a[0]-b[0]));
		type.push_back(9);
		cost.push_back(abs(a[0]-b[n-1]));
		
		type.push_back(6);
		cost.push_back(abs(a[n-1]-b[0]));
		type.push_back(10);
		cost.push_back(abs(a[n-1]-b[n-1]));
		
		{
			auto t = b;
			sort(t.begin(),t.end());
			int d = distance(t.begin(),lower_bound(t.begin(),t.end(),a[0]));
			if(d!=t.size()){
				type.push_back(1);
				cost.push_back(abs(a[0]-t[d]));
			}
			d--;
			if(d>=0){
				type.push_back(1);
				cost.push_back(abs(a[0]-t[d]));
			}
			
			d = distance(t.begin(),lower_bound(t.begin(),t.end(),a[n-1]));
			if(d!=t.size()){
				type.push_back(2);
				cost.push_back(abs(a[n-1]-t[d]));
			}
			d--;
			if(d>=0){
				type.push_back(2);
				cost.push_back(abs(a[n-1]-t[d]));
			}
		}
		
		{
			auto t = a;
			sort(t.begin(),t.end());
			int d = distance(t.begin(),lower_bound(t.begin(),t.end(),b[0]));
			if(d!=t.size()){
				type.push_back(4);
				cost.push_back(abs(b[0]-t[d]));
			}
			d--;
			if(d>=0){
				type.push_back(4);
				cost.push_back(abs(b[0]-t[d]));
			}
			
			d = distance(t.begin(),lower_bound(t.begin(),t.end(),b[n-1]));
			if(d!=t.size()){
				type.push_back(8);
				cost.push_back(abs(b[n-1]-t[d]));
			}
			d--;
			if(d>=0){
				type.push_back(8);
				cost.push_back(abs(b[n-1]-t[d]));
			}
		}
		vector<long long> dp(1<<4,Inf);
		dp[0] = 0;
		rep(i,1<<4){
			rep(j,type.size()){
				dp[i|type[j]] = min(dp[i|type[j]], dp[i] + cost[j]);
			}
		}
		cout<<dp.back()<<endl;
		
	}
	
	return 0;
}