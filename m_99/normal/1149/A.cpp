#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001



int main(){
	
	int n;
	cin>>n;
	
	vector<int> ans;
	
	int c1 = 0,c2 = 0;
	rep(i,n){
		int a;
		scanf("%d",&a);
		if(a==1)c1++;
		else c2++;
	}
	
	if(c2>0){
		ans.push_back(2);
		c2--;
	}
	if(c1>0){
		ans.push_back(1);
		c1--;
	}
	
	rep(i,c2)ans.push_back(2);
	rep(i,c1)ans.push_back(1);
	
	rep(i,n){
		if(i!=0)printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	
	return 0;
}