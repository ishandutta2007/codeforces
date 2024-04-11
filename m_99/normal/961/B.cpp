#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int n,k;
	scanf("%d %d",&n,&k);
	
	vector<int> a(n);
	rep(i,n){
		scanf("%d",&a[i]);
	}
	vector<int> t(n);
	rep(i,n){
		scanf("%d",&t[i]);
	}
	
	int ans = 0;
	int cur = 0;
	rep(i,n){
		if(t[i])ans += a[i];
	}
	cur = ans;
	
	rep(i,n){
		if(t[i]==0){
			cur += a[i];
		}
		if(i-k>=0){
			if(t[i-k]==0)cur -= a[i-k];
		}
		ans = max(ans,cur);
	}
	cout<<ans<<endl;
	
    return 0;
}