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
		
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
		}
		
		vector<int> ans;
		
		rep(i,n-1){
			if(a[i]==0&&a[i+1]==1){
				rep(j,i+1)ans.push_back(j);
				ans.push_back(n);
				for(int j=i+1;j<n;j++)ans.push_back(j);
				break;
			}
		}
		if(ans.size()==0){
			if(a[0]==1){
				ans.push_back(n);
				rep(i,n)ans.push_back(i);
			}
		}
		if(ans.size()==0){
			if(a.back()==0){
				rep(i,n)ans.push_back(i);
				ans.push_back(n);
			}
		}
		
		if(ans.size()==0)printf("-1\n");
		else{
			rep(i,n+1){
				if(i!=0)printf(" ");
				printf("%d",ans[i]+1);
			}
			printf("\n");
		}
		
	}
	
	return 0;
}