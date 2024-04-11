#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<string> s(n);
		rep(i,n)cin>>s[i];
		
		vector<int> x,y;
		rep(i,n){
			rep(j,n){
				if(s[i][j]=='*'){
					x.push_back(i);
					y.push_back(j);
				}
			}
		}
		sort(x.begin(),x.end());
		x.erase(unique(x.begin(),x.end()),x.end());
		sort(y.begin(),y.end());
		y.erase(unique(y.begin(),y.end()),y.end());
		if(x.size()==1){
			if(x[0]==0)x.push_back(1);
			else x.push_back(0);
		}
		if(y.size()==1){
			if(y[0]==0)y.push_back(1);
			else y.push_back(0);
		}
		rep(i,2){
			rep(j,2){
				s[x[i]][y[j]] = '*';
			}
		}
		rep(i,n)cout<<s[i]<<endl;
		
	}
	
	return 0;
}