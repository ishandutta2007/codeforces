#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){	

	int r,n;
	cin>>r>>n;
	
	vector<int> t(n),x(n),y(n);
	rep(i,n){
		scanf("%d %d %d",&t[i],&x[i],&y[i]);
	}
	t.insert(t.begin(),0);
	x.insert(x.begin(),1);
	y.insert(y.begin(),1);
	
	vector<int> ans(n+1,-Inf);
	ans[0] = 0;
	int M = -Inf;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			if(abs(j-i)>=2*r){
				M = max(M,ans[j]+1);
				break;
			}
			if(abs(x[j]-x[i])+abs(y[j]-y[i])<=abs(t[j]-t[i])){
				ans[i] = max(ans[i],ans[j]+1);
			}
		}
		ans[i] = max(ans[i],M);
	}
	
	int Ans = 0;
	rep(i,n+1)Ans = max(Ans,ans[i]);
	
	cout<<Ans<<endl;
	
    return 0;
}