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
		
		int a = 0;
		rep(i,n*2){
			int x;
			cin>>x;
			
			if(x%2==0)a++;
		}
		
		if(a==n)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
	}
	
    return 0;
}