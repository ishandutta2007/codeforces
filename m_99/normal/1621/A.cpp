#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		
		vector<string> ans(n,string(n,'.'));
		bool f = true;
		rep(i,k){
			int x = i*2;
			if(x>=n){
				f = false;
				break;
			}
			ans[x][x] = 'R';
		}
		if(!f)cout<<-1<<endl;
		else{
			rep(i,n)cout<<ans[i]<<endl;
		}
			
			
		
	}
	
	return 0;
}