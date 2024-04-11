#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> x(n);
		rep(i,n)cin>>x[i];
		
		set<int> S;
		
		rep(i,n){
			rep(j,n){
				S.insert(abs(x[j]-x[i]));
			}
		}
		
		cout<<S.size()-1<<endl;
		
		
		
		
		
	}
	
    return 0;
}