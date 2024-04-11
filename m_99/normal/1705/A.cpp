#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,x;
		cin>>n>>x;
		
		vector<int> h(n*2);
		rep(i,n*2)cin>>h[i];
		sort(h.begin(),h.end());
		bool f = true;
		rep(i,n){
		if(h[i] + x <= h[i+n])continue;
		f = false;
		}
		if(f){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
		
		
	}
	
	
    return 0;
}