#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000


int main(){
	
	vector<long long> ans(51,Inf);
	
	string s = "0123456789";
	
	do{
		if(s[0]=='0')continue;
		long long L = 0;
		rep(i,s.size()){
			L *= 10;
			L += s[i]-'0';
			int sum = 0;
			long long l = L;
			while(l!=0){
				sum += l%10;
				l/=10;
			}
			ans[sum] = min(ans[sum],L);
		}
		
		
	}
	while(next_permutation(s.begin(),s.end()));
	
	rep(i,51){
		if(ans[i]==Inf)ans[i] = -1;
	}
	
	int _t;
	cin>>_t;
	
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		cout<<ans[n]<<endl;
	}
	
	
    return 0;
}