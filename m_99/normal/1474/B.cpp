#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	vector<int> p;
	vector<bool> isp(500000,true);
	
	for(int i=2;i<isp.size();i++){
		if(isp[i]){
			p.push_back(i);
			for(int j=i;j<isp.size();j+=i)isp[j] = false;
		}
	}
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long d;
		scanf("%lld",&d);
		
		long long p0 = *(lower_bound(p.begin(),p.end(),1+d));
		long long p1 = *(lower_bound(p.begin(),p.end(),p0 + d));
		
		long long ans = min(p0*p0*p0,p0*p1);
		
		printf("%lld\n",ans);
		
	}
	
    return 0;
}