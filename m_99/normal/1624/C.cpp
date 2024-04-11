#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<bool> f(n,false);
		priority_queue<int> Q;
		rep(i,n){
			int a;
			cin>>a;
			Q.push(a);
		}
		while(Q.size()!=0 && Q.top()>0){
			int t = Q.top();
			Q.pop();
			if(t <= n && t >= 1 && f[t-1] == false){
				f[t-1] = true;
			}
			else{
				Q.push(t/2);
			}
		}
		
		bool F = true;
		rep(i,n){
			if(!f[i])F = false;
		}
		if(F)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
	}
	
	return 0;
}