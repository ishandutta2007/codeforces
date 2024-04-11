#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		vector<int> b(7);
		rep(i,7)cin>>b[i];
		
		int a1 = b[0],a2 = b[1];
		int a3 = b.back() - a1 - a2;
		cout<<a1<<' '<<a2<<' '<<a3<<endl;
		
		
	}
	
	return 0;
}