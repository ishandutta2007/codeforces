#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
int query(vector<int> t){
	cout<<"?";
	rep(i,t.size()){
		cout<<' '<<t[i];
	}
	cout<<endl;
	int ret;
	cin>>ret;
	return ret;
}
int answer(vector<int> t){
	cout<<"!";
	rep(i,t.size()){
		cout<<' '<<t[i];
	}
	cout<<endl;
	return 0;
}

int main(){
	
	int n;
	cin>>n;
	vector<int> ans(n,0);
	rep(i,n-1){
		vector<int> t(n,1);
		t.back() = i+2;
		int p = query(t);
		p--;
		if(p!=-1){
			ans[p] = t.back() - t[0];
		}
	}
	rep(i,n-1){
		vector<int> t(n,2+i);
		t.back() = 1;
		int p = query(t);
		p--;
		if(p!=-1){
			ans[p] = t.back() - t[0];
		}
	}
	
	int mini = Inf;
	rep(i,n)mini = min(mini,ans[i]);
	mini *= -1;
	mini++;
	
	rep(i,n)ans[i] += mini;
	
	answer(ans);
	
	return 0;
}