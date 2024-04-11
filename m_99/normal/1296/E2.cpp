#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int n;
	string s;
	cin>>n>>s;
	
	vector<int> ans(n);
	
	vector<vector<int>> ind(26);
	
	rep(i,n){
		int t = s[i]-'a';
		int x = -1;
		for(int j=t;j>=0;j--){
			if(ind[j].size()!=0){
				x = j;
				break;
			}
		}
		int y;
		if(x!=-1){
			y = ind[x].back();
			ind[x].pop_back();
		}
		else{
			y = 0;
			rep(j,26)y += ind[j].size();
		}
		ind[t].push_back(y);
		ans[i] = ind[t].back();
	}
	
	int x = 0;
	rep(i,26)x += ind[i].size();
	
	cout<<x<<endl;
	rep(i,n){
		if(i!=0)printf(" ");
		printf("%d",ans[i]+1);
	}
	cout<<endl;
	
	return 0;
}