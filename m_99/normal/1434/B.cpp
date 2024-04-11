#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int n;
	cin>>n;
	
	string S(2*n,'.');
	vector<int> ind(2*n,-1);
	
	rep(i,2*n){
		char c;
		scanf("%c",&c);
		scanf("%c",&S[i]);
		if(S[i]=='-')scanf("%d",&ind[i]);
	}
	
	
	set<int> X;
	rep(i,n){
		X.insert(i+1);
	}
	
	vector<int> ans;
	vector<pair<int,int>> store;
	vector<int> left(n,0);
	rep(i,2*n){
		if(S[i]=='+'){
			auto it = X.end();
			it--;
			left[store.size()] = 0;
			store.emplace_back(*(it),ans.size());
			X.erase(it);
			ans.push_back(0);
		}
		else{
			int x = ind[i];
			if(store.size()==0){
				cout<<"NO"<<endl;
				return 0;
			}
			if(store.back().first<x){
				cout<<"NO"<<endl;
				return 0;
			}
			if(x<left[store.size()-1]){
				cout<<"NO"<<endl;
				return 0;
			}
			
			ans[store.back().second] = x;
			X.insert(store.back().first);
			X.erase(x);
			store.pop_back();
			if(store.size()>0){
				left[store.size()-1] = max({left[store.size()],left[store.size()-1],x});
			}
		}
	}
	cout<<"YES"<<endl;
	
	rep(i,n){
		if(i!=0)printf(" ");
		printf("%d",ans[i]);
	}
	cout<<endl;
	
    return 0;
}