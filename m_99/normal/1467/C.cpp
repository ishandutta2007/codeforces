#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

int get(int a,int b,int c){
	if(a>b&&c>b)return 1;
	if(a<b&&c<b)return 1;
	return 0;
}

int main(){

	vector<int> n(3);
	rep(i,3)cin>>n[i];
	
	vector<vector<long long>> a(3);
	rep(i,3){
		a[i].resize(n[i]);
		
		rep(j,n[i]){
			scanf("%lld",&a[i][j]);
		}
		sort(a[i].begin(),a[i].end());
	}
	
	long long mini = Inf;
	
	mini = min({mini,a[0][0]+a[1][0],a[0][0]+a[2][0],a[1][0]+a[2][0]});
	long long ans = 0LL;
	rep(i,3){
		long long S = 0LL;
		rep(j,n[i]){
			S += a[i][j];
		}
		mini = min(mini,S);
		ans += S;
	}
	
	cout<<ans-mini*2<<endl;
	
    return 0;
}