#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
#define InfL 4000000000000000001

int main() {	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long a,b,c,d;
		cin>>a>>b>>c>>d;
		long long x = a*d;
		long long y = b*c;
		if(x==y)cout<<0<<endl;
		else{
			if(x==0 || y==0 || x%y==0 || y%x==0)cout<<1<<endl;
			else cout<<2<<endl;
		}
		
		
	}
	
    return 0;
}