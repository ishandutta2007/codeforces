#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int n,q;
	scanf("%d %d",&n,&q);
	
	vector<vector<int>> ind(50);
	
	rep(i,n){
		int a;
		scanf("%d",&a);
		a--;
		ind[a].push_back(i);
	}
	vector<int> ans(q);
	rep(i,q){
		
		int t;
		scanf("%d",&t);
		t--;
		
		ans[i] = ind[t][0];
		ind[t][0] = 0;
		
		rep(j,50){
			if(j==t)continue;
			rep(k,ind[j].size()){
				if(ind[j][k]>=ans[i])break;
				ind[j][k]++;
			}
		}		
		
	}
	
	rep(i,q){
		if(i!=0)printf(" ");
		printf("%d",ans[i]+1);
	}
	cout<<endl;
	
    return 0;
}