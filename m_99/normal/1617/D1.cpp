#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int query(int a,int b,int c){
	cout<<"? "<<a+1<<' '<<b+1<<' '<<c+1<<endl;
	int ret;
	cin>>ret;
	return ret;
}

void answer(vector<int> ans){
	cout<<"! "<<ans.size();
	rep(i,ans.size()){
		cout<<' '<<ans[i]+1;
	}
	cout<<endl;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		int last = query(0,1,2);
		vector<int> ans(n,-1);
		int x,y;
		for(int i=1;i<n;i++){
			int t = query(i,i+1,i+2);
			if(t==last)continue;
			ans[i+2] = t;
			ans[i-1] = last;
			x = i-1,y = i+2;
			break;
		}
		rep(i,n){
			if(ans[i]==-1){
				ans[i] = query(i,x,y);
			}
		}
		vector<int> p;
		rep(i,n){
			if(ans[i]==0)p.push_back(i);
		}
		answer(p);
		
		
	}
	
	return 0;
}