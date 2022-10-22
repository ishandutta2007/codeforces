#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){
	
	int _t;
	cin>>_t;
	
	
	
	
	rep(_,_t){
		
		int n,d;
		cin>>n>>d;
		
		vector<int> depth(n,1);
		int cur = 0;
		rep(i,n)cur += i;
		
		if(cur < d){
			cout<<"NO"<<endl;
			continue;
		}
		
		while(cur>d){
			int x = 1;
			for(int i=1;i<n;i++){
				if(depth[i]<depth[i-1]*2){
					x = i;
					break;
				}
			}
			int y = n-1;
			for(int i=n-1;i>=0;i--){
				if(depth[i]>0){
					y = i;
					break;
				}
			}
			if(x>=y)break;
			
			if(cur-d >= y-x){
				cur -= y-x;
				depth[y]--;
				depth[x]++;
			}
			else{
				while(cur!=d){
					cur -= y;
					depth[y]--;
					y--;
					depth[y]++;
					cur+=y;
				}
				break;
			}
		}
		if(cur!=d){
			cout<<"NO"<<endl;
			continue;
		}
		
		vector<vector<int>> temp(n);
		cur = 0;
		rep(i,n){
			rep(j,depth[i]){
				temp[i].push_back(cur);
				cur++;
			}
		}
		cout<<"YES"<<endl;
		vector<int> ans(n);
		for(int i=1;i<n;i++){
			rep(j,temp[i].size()){
				int t = j;
				t %= temp[i-1].size();
				ans[temp[i][j]] = temp[i-1][t];
			}
		}
		
		for(int i=1;i<n;i++){
			if(i!=1)printf(" ");
			printf("%d",ans[i]+1);
		}
		printf("\n");
		
	}
	
	return 0;
}