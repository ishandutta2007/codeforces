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
		
		int a,b;
		cin>>a>>b;
		
		vector<bool> used(n,false);
		vector<int> x(1,a),y(1,b);
		used[a-1] = true;
		used[b-1] = true;
		rep(i,n/2-1){
			while(used.back()){
				used.pop_back();
			}
			x.push_back(used.size());
			used.pop_back();
		}
		rep(i,used.size()){
			if(!used[i])y.push_back(i+1);
		}
		bool f = true;
		rep(i,n/2){
			if(x[i]<a||y[i]>b){
				f = false;
			}
			x.push_back(y[i]);
		}
		if(!f)cout<<-1<<endl;
		else{
			rep(i,n){
				if(i!=0)cout<<' ';
				cout<<x[i];
			}
			cout<<endl;
		}
	}
	
	return 0;
}