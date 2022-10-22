#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000000000000


int main(){
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		long long a,b,c;
		cin>>a>>b>>c;
		
		cout<<max(0LL,(max(b,c)+1-a))<<' '<<max(0LL,(max(a,c)+1-b))<<' '<<max(0LL,(max(a,b)+1-c))<<endl;
		
	}
	
	return 0;
}