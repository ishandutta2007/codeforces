#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m,r,c;
		cin>>n>>m>>r>>c;
		r--;c--;
		vector<string> s(n);
		rep(i,n)cin>>s[i];
		
		if(s[r][c]=='B'){
			cout<<0<<endl;
			continue;
		}
		if(s==vector<string>(n,string(m,'W'))){
			cout<<-1<<endl;
			continue;
		}
		bool f= false;
		rep(i,n){
			rep(j,m){
				if(s[i][j]=='B'){
					if(i==r || j==c)f = true;
				}
			}
		}
		if(f)cout<<1<<endl;
		else cout<<2<<endl;
		
	}
	
	return 0;
}