#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000


int main(){	
	
	int t;
	cin>>t;
	rep(_,t){
		int n;
		cin>>n;
		vector<int> a(n);
		
		rep(i,n){
			scanf("%d",&a[i]);
		}
		
		vector<int> ind;
		rep(i,n){
			if(ind.size()==0)ind.push_back(i);
			else{
				if(a[ind[0]]!=a[i]){
					ind.push_back(i);
					break;
				}
			}
		}
		if(ind.size()==1){
			cout<<"NO"<<endl;
			continue;
		}
		vector<pair<int,int>> ans;
		ans.emplace_back(ind[0],ind[1]);
		rep(i,n){
			if(i==ind[0]||i==ind[1])continue;
			if(a[i]!=a[ind[0]])ans.emplace_back(i,ind[0]);
			else ans.emplace_back(i,ind[1]);
		}
		cout<<"YES"<<endl;
		rep(i,n-1){
			cout<<ans[i].first+1<<' '<<ans[i].second+1<<endl;
		}
		
	}
		
    return 0;
}