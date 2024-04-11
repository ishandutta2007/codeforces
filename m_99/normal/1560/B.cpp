#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int a,b,c;
		cin>>a>>b>>c;
		
		if(a>b)swap(a,b);
		int n = b-a;
		
		if(a>n*2||b>n*2||c>n*2){
			printf("-1\n");
		}
		else{
			if(c<=n)c += n;
			else c -= n;
			cout<<c<<endl;
			
		}
		
	}
	
	return 0;
}