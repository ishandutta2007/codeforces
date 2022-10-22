#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001
	

int main(){
	
	vector<long long> t;
	for(long long i=1;i<=10000;i++){
		t.push_back(i*i*i);
	}
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long x;
		scanf("%lld",&x);
		int f = 0;
		rep(i,t.size()){
			if(binary_search(t.begin(),t.end(),x-t[i]))f=1;
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
    return 0;
}