#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<bool> ok(m+1,false);
	ok[0] = true;
	vector<int> ans(m+1,Inf);
	
	rep(i,n){
		long long t,x,y;
		scanf("%lld %lld %lld",&t,&x,&y);
		if(t==1){
			x = (x+100000-1)/100000;
			
			for(int j=m;j>=0;j--){
				
				if(ok[j]==false)continue;
				long long temp = j;
				rep(k,y){
					temp += x;
					if(temp==j)break;
					if(temp>m)break;
					if(ok[temp])break;
					ok[temp] = true;
				}
				
			}
			
		}
		else{
			
			for(int j=m;j>=0;j--){
				
				if(ok[j]==false)continue;
				long long temp = j;
				rep(k,y){
					temp *= x;
					if(temp==j)break;
					temp = (temp+100000-1)/100000;
					if(temp>m)break;
					if(ok[temp])break;
					ok[temp] = true;
				}
				
			}
			
		}
		rep(j,m+1){
			if(ok[j])ans[j] = min(ans[j],i);
		}
	}
	
	for(int j=1;j<=m;j++){
		if(j!=1)printf(" ");
		int p = ans[j];
		if(p==Inf)printf("-1");
		else printf("%d",p+1);
	}
	cout<<endl;
	
    return 0;
}