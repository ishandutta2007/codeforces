#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

int main(){

	int _t;
	scanf("%d",&_t);
	
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		string s(n,'.');
		rep(i,n){
			if(i==0)s[i] = '9';
			else if(i==1)s[i] = '8';
			else{
				int t = 9;
				t += (i-2);
				t %= 10;
				s[i] = '0'+t;
			}
		}
		
		cout<<s<<endl;
		
		
	}
	
    return 0;
}