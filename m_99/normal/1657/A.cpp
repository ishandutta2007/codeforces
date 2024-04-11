#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int x,y;
		cin>>x>>y;
		int D = x*x + y*y;
	
		int ans = 2;
		rep(i,300){
			if(i*i==D){
				ans = 1;
			}
		}
		if(D==0)ans = 0;
		cout<<ans<<endl;
		
	}
	
	return 0;
}