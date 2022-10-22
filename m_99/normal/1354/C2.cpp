#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	int t;
	cin>>t;
	
	double PI = acos(-1.0);
	
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		
		double ans = 10000.0;
		
		double r = 0.0;
		for(int i=0;i<n;i++){
			r += abs(sin(PI/2.0 + (double)i * PI / (double)n));
		}
		r /= 2.0;
		
		double ok = 0.0,ng = PI / (2.0 * (double)n);
		for(int i=0;i<30;i++){
			double mid = (ok+ng)/2.0;
			vector<pair<double,double>> V;
			for(int j=0;j<2*n;j++){
				V.emplace_back(r*cos(mid+(double)j*PI/(double)n),r*sin(mid+(double)j*PI/(double)n));
			}
			
			double d1 = 0.0,d2=0.0;
			for(int i=0;i<n;i++){
				d1 = max(d1,abs(V[i].first-V[i+n].first));
				d2 = max(d2,abs(V[i].second - V[i+n].second));
			}

			ans = min(ans,max(d1,d2));
			
			if(d1>d2)ok = mid;
			else ng = mid;
		}
		
		
		
		cout<<fixed<<setprecision(10)<<ans<<endl;
	}
	
	return 0;
}