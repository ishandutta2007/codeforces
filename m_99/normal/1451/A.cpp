#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

	

int main(){
	
	int t;
	cin>>t;
	
	rep(_,t){
		int N;
		cin>>N;
		
		if(N==1)cout<<0<<endl;
		else if(N==2)cout<<1<<endl;
		else if(N==3)cout<<2<<endl;
		else{
			if(N%2==0)cout<<2<<endl;
			else cout<<3<<endl;
		}
	}
	
    return 0;
}