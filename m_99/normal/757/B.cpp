#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int n;
	cin>>n;
	
	vector<int> cnt(100001,0);
	rep(i,n){
		int s;
		scanf("%d",&s);
		cnt[s]++;
	}
	int ans = 1;
	for(int i=2;i<=100000;i++){
		int t = 0;
		for(int j=i;j<=100000;j+=i){
			t += cnt[j];
		}
		ans = max(ans,t);
	}
	cout<<ans<<endl;
	
    return 0;
}