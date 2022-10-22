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
		long long k;
		cin>>n>>k;;
		
		vector<long long> a(n);
		rep(i,n)scanf("%lld",&a[i]);
		sort(a.begin(),a.end());
		a.insert(a.begin(),0LL);
		long long ans = 1000000000000000000;
		rep(i,n)a[i+1] += a[i];
		
		rep(i,n){
			long long sum = a[n-i] - a[1];
			
			long long ok = 1000000000000000,ng = -1;
			while(ok-ng>1LL){
				long long mid = (ok+ng)/2;
				__int128 temp = a[1]-mid;
				temp *= i+1;
				temp += sum;
				if(temp <= k)ok = mid;
				else ng = mid;
			}
		//	cout<<ok<<endl;
			ans = min(ans,ok + i);
			
		}
		cout<<ans<<endl;
	}
	
	return 0;
}