#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	set<long long> ok;
	
	for(long long i=1;i<=30000;i++){
		ok.insert(i*i*2);
		ok.insert(i*i*4);
	}
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		if(ok.count(n))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
    return 0;
}