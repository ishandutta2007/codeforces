#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300

int main(){
	
	int t;
	cin>>t;
	
	rep(_,t){
		int n,x,y;
		cin>>n>>x>>y;
		
		int mini = Inf;
		int a0 = -1;
		int d = -1;
		
		for(int i=1;i<=min(x,y);i++){
			for(int j=1;j<=55;j++){
				if((x-i)%j!=0)continue;
				if((y-i)%j!=0)continue;
				if((x-i)/j >= n)continue;
				if((y-i)/j >= n)continue;
				if(mini>i + (n-1) * j){
					mini = i + (n-1)*j;
					a0 = i;
					d = j;
				}
			}
		}
		
		rep(i,n){
			if(i!=0)cout<<' ';
			cout<<a0+d*i;
		}
		cout<<endl;
		
	}
	
    return 0;
}