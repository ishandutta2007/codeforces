#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> p(n);
		set<int> S;
		rep(i,n){
			scanf("%d",&p[i]);
			S.insert(p[i]);
		}
		
		vector<int> ans;
		vector<bool> used(n,false);
		int pos = n-1;
		while(S.size()!=0){
			ans.push_back((*S.begin()));
			while(true){
				S.erase(p[pos]);
				pos--;
				if(p[pos+1]==ans.back()){
					used[pos+1] = true;
					break;
				}
			}
		}
		rep(i,n){
			if(!used[i]){
				ans.push_back(p[i]);
			}
		}
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	
	return 0;
}