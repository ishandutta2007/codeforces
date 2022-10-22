#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300

vector<pair<int,int>> ans;

void go(int l,int r){
	for(int i=1;true;i<<=1){
		if(l+i==r)break;
		set<int> S;
		for(int j=l;j+i<r;j++){
			if(S.count(j))continue;
			ans.emplace_back(j,j+i);
			S.insert(j+i);
		}
	}
}

int main(){	
	
	int n;
	cin>>n;
	
	int t = 1;
	while(true){
		if(t*2 >= n){
			go(0,t);
			go(n-t,n);
			break;
		}
		else{
			t*=2;
		}
	}
	
	
	cout<<ans.size()<<endl;
	
	rep(i,ans.size()){
		printf("%d %d\n",ans[i].first+1,ans[i].second+1);
	}
	
    return 0;
}