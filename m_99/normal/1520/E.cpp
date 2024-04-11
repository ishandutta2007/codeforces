#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

int main(){
	
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		
		string s;
		cin>>s;
		
		vector<long long> imosx(n+1,0),imos(n+1,0);
		int cur = 0;
		rep(i,s.size()){
			if(s[i]=='*'){
				imosx[0]--;
				imosx[i-cur+1]++;
				imosx[i-cur+1]++;
				imos[0] += i-cur;
				imos[i-cur+1] -= i-cur;
				imos[i-cur+1] += -i+cur;
				cur++;
			}
		}
		
		rep(i,n){
			imosx[i+1] += imosx[i];
			imos[i+1] += imos[i];
		}
		
		long long ans = Inf;
		rep(i,n){
			if(i+cur>n)break;
			ans = min(ans,imosx[i] * i + imos[i]);
		}
		
		printf("%lld\n",ans);
		
	}
	
    return 0;
}