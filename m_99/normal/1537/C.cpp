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
		scanf("%d",&n);
		
		vector<int> h(n);
		rep(i,n)scanf("%d",&h[i]);
		
		sort(h.begin(),h.end());
		
		int ind = 0;
		rep(i,n-1){
			if(abs(h[ind]-h[ind+1]) > abs(h[i]-h[i+1]))ind = i;
		}
		
		vector<int> ans;
		ans.push_back(h[ind]);
		for(int i=ind+2;i<n;i++)ans.push_back(h[i]);
		rep(i,ind)ans.push_back(h[i]);
		ans.push_back(h[ind+1]);
		
		
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
		
	}
	
	return 0;
}