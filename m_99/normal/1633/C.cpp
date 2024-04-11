#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long hc,dc,hm,dm;
		cin>>hc>>dc>>hm>>dm;
		
		long long k,w,a;
		cin>>k>>w>>a;
		bool f = false;
		
		rep(i,k+1){
			long long hh = hc + a * i;
			long long dd = dc + w * (k-i);
			long long x = (hm + dd - 1)/dd;
			long long y = (hh + dm - 1)/dm;
			if(x<=y)f = true;
			
		}
		
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	return 0;
}