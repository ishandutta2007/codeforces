#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){

	int n;
	cin>>n;
	
	vector<long long> d(n);
	
	rep(i,n)cin>>d[i];
	
	set<long long> S;
	
	long long sum1 = 0LL;
	S.insert(0LL);
	
	rep(i,n){
		sum1 += d[i];
		S.insert(sum1);
	}
	
	reverse(d.begin(),d.end());
	
	long long sum3 = 0LL;
	
	long long ans = 0LL;
	
	rep(i,n){
		sum3 += d[i];
		if(sum3*2 > sum1)break;
		if(S.count(sum3)){
			ans = sum3;
		}
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}