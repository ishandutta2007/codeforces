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
		
		vector<pair<long long,int>> a(n);
		rep(i,n){
			scanf("%lld",&a[i].first);
			a[i].second = i+1;
		}
		sort(a.rbegin(),a.rend());
		vector<long long> pos(n+1);
		pos[0] = 0;
		long long ans = 0LL;
		
		rep(i,n){
			long long d = (i+2)/2;
			ans += d * a[i].first * 2;
			if(i%2==0){
				pos[a[i].second] = d;
			}
			else{
				pos[a[i].second] = -d;
			}
		}
		cout<<ans<<endl;
		rep(i,n+1){
			if(i!=0)printf(" ");
			printf("%lld",pos[i]);
		}
		cout<<endl;
	}
		
	return 0;
}