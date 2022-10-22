#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		cin>>n;
		vector<int> r(n);
		rep(i,n)cin>>r[i];
		
		cin>>m;
		vector<int> b(m);
		rep(i,m)cin>>b[i];
		
		int x = 0,y = 0;
		int cur = 0;
		
		rep(i,n){
			cur += r[i];
			x = max(x,cur);
		}
		
		cur = 0;
		rep(i,m){
			cur += b[i];
			y = max(y,cur);
		}
		
		cout<<x+y<<endl;
		
		
		
		
	}
	
    return 0;
}