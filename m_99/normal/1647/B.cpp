#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		cin>>n>>m;
		vector<string> s(n);
		rep(i,n)cin>>s[i];
		bool f = true;
		rep(i,n-1){
			rep(j,m-1){
				int t = 0;
				rep(k,2){
					rep(l,2){
						t += s[i+k][j+l]-'0';
					}
				}
				if(t==3)f = false;
			}
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	return 0;
}