#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 2000000000000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k,r,c;
		cin>>n>>k>>r>>c;
		r--,c--;
		int x=0,y=0;
		rep(i,n){
			rep(j,n){
				if((i+j)%k == (r+c)%k)x++;
				if((n+i-j)%k == (n+r-c)%k)y++;
			}
		}
		vector<string> ans(n,string(n,'.'));
		rep(i,n){
			rep(j,n){
				if((i+j)%k == (r+c)%k && x<y)ans[i][j] = 'X';
				if((n+i-j)%k == (n+r-c)%k && x>=y)ans[i][j] = 'X';
			}
		}
		rep(i,n)cout<<ans[i]<<endl;
	}
	
    return 0;
}