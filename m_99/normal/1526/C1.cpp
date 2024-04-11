#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf (long long)1000000000000000


int main(){
	
	int n;
	cin>>n;
	
	vector<long long> a(n);
	rep(i,n){
		scanf("%lld",&a[i]);
	}
	int ans = 0;
	
	priority_queue<long long> Q;
	long long sum0 = 0LL;
	long long sum1 = 0LL;
	rep(i,a.size()){
		
		if(a[i] >= 0){
			sum0 += a[i];
			ans++;
		}
		else{
			if(sum1 - a[i] > sum0){
				if(Q.size()==0)continue;
				a[i] *= -1;
				if(Q.top()>a[i]){
					sum1 -= Q.top();
					sum1 += a[i];
					Q.pop();
					Q.push(a[i]);
				}
			}
			else{
				sum1 -= a[i];
				Q.push(-a[i]);
			}
		}
	}
	
	
	cout<<ans+Q.size()<<endl;
	
	return 0;
}