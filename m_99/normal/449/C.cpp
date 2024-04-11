#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000



int main(){
	
	int n;
	cin>>n;
	
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	
	vector<vector<int>> L(n+1,vector<int>());
	vector<int> p(n+1,-1);
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			if(p[j]==-1){
				L[i].push_back(j);
				p[j] = i;
			}
		}
	}
	
	vector<bool> used(n+1,false);
	
	vector<int> a,b;
	
	for(int i=n;i>=3;i--){
		while(L[i].size()>=2){
			rep(j,2){
				if(j==0)a.push_back(L[i].back());
				else b.push_back(L[i].back());
				L[i].pop_back();
			}			
		}
		if(L[i].size()==1){
			if(L[i][0]*2<=n){
				a.push_back(L[i][0]);
				b.push_back(L[i][0]*2);
				
				used[L[i][0]*2] = true;
			}
		}
	}
	
	vector<int> temp;
	rep(i,L[2].size()){
		if(!used[L[2][i]])temp.push_back(L[2][i]);
	}
	
	while(temp.size()>=2){
		rep(i,2){
			if(i==0)a.push_back(temp.back());
			else b.push_back(temp.back());
			temp.pop_back();
		}
	}
	
	cout<<a.size()<<endl;

	
	rep(i,a.size()){
		printf("%d %d\n",a[i],b[i]);
	}
		
	
    return 0;
}