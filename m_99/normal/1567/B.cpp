#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	vector<int> sum(300005,0);
	rep(i,sum.size()){
		if(i==0)continue;
		sum[i] = sum[i-1] ^ i;
	}
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int a,b;
		cin>>a>>b;
		
		int ans = a;
		int S = sum[a-1];
		S ^= b;
		if(S!=0){
			if(a==S)ans+=2;
			else ans++;
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}