#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

long long gcd(long long a, long long b){
	if (b == 0) return a;
	return gcd(b, a % b);
}



int main(){

	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		long long a,m;
		cin>>a>>m;
		long long g = gcd(a,m);
		a /= g;
		m /= g;
		
		long long c = m;
		
		vector<long long> p;
		for(long long i=2;i*i<=m;i++){
			if(m%i==0){
				p.push_back(i);
				while(m%i==0)m/=i;
			}
		}
		
		if(m!=1)p.push_back(m);
		
		long long ans = 0;
		for(int i=0;i<(1<<p.size());i++){
			long long x = 1;
			int cnt = 0;
			for(int j=0;j<p.size();j++){
				if((1<<j)&i){
					x *= p[j];
					cnt++;
				}
			}
			long long yeah = (a+c-1)/x - (a-1)/x;
			if(cnt%2==0)ans += yeah;
			else ans -= yeah;
		}
		cout<<ans<<endl;
			
		
	}
	
	return 0;
}