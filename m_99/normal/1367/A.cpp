#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		string a;
		cin>>a;
		string b = a.substr(0,2);
		
		for(int i=3;i<a.size();i+=2)b += a[i];
		cout<<b<<endl;
		
	}
		
	
	return 0;
}