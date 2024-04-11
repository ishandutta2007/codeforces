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
		scanf("%d",&n);
		bool f = false;
		rep(i,1000000){
			n -= 2020;
			if(n<0)break;
			if(n <= (i+1)){
				f=true;
				break;
			}
		}
		
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		
	}
	
    return 0;
}