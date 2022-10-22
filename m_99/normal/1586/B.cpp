#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		scanf("%d %d",&n,&m);
		vector<bool> ok(n,true);
		rep(i,m){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			ok[b-1] = false;
		}
		
		int ans = 0;
		rep(i,n){
			if(ok[i])ans = i;
		}
		
		rep(i,n){
			if(i==ans)continue;
			printf("%d %d\n",i+1,ans+1);
		}
		
	}
	
	
	return 0;
}