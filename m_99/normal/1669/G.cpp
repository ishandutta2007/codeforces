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
		cin>>n>>m;
		vector<string> s(n);
		rep(i,n)cin>>s[i];
		
		for(int i=n-2;i>=0;i--){
			rep(j,m){
				if(s[i][j]=='*'){
					int ii = i;
					while(ii!=n-1 && s[ii+1][j]=='.'){
						swap(s[ii][j],s[ii+1][j]);
						ii++;
					}
				}
			}
		}
		rep(i,n)cout<<s[i]<<endl;
	}
	
	
    return 0;
}