#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int query(int x){
	cout<<"? "<<x+1<<endl;
	int ret;
	scanf("%d",&ret);
	return ret-1;
}

void answer(vector<int> ans){
	cout<<"!";
	rep(i,ans.size()){
		printf(" %d",ans[i]+1);
	}
	cout<<endl;
}

void solve(){
	int n;
	cin>>n;
	//query(0);
	
	vector<int> ans(n,-1);
	
	rep(i,n){
		if(ans[i]!=-1)continue;
		deque<int> D;
		set<int> S;
		
		while(true){
			int ret = query(i);
			if(S.count(ret))break;
			D.push_back(ret);
			S.insert(ret);
		}
		while(D.back()!=i){
			D.push_back(D.front());
			D.pop_front();
		}
		int last = i;
		rep(j,D.size()){
			ans[last] = D[j];
			last = D[j];
		}
	}
	
	answer(ans);
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		solve();
			
		
	}
	
	return 0;
}