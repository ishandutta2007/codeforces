#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

bool check(int t){
	int cnt = 0;
	for(int i=1;i<=t;i++){
		if(t%i==0)cnt++;
	}
	return cnt!=2;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		int S = 0;
		rep(i,n){
			cin>>a[i];
			S += a[i];
		}
		vector<int> ans(n);
		rep(i,n)ans[i] = i;
		if(check(S)){
			
		}
		else{
			rep(i,n){
				if(check(S-a[i])){
					ans.erase(ans.begin()+i);
					break;
				}
			}
		}
				
		
		printf("%d\n",ans.size());
		rep(i,ans.size()){
			if(i!=0)printf(" ");
			printf("%d",ans[i]+1);
		}
		printf("\n");
		
	}
	
	
	return 0;
}