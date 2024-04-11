#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

double get(double p,int n){
	return pow(p,n-1) * (1.0-p) * n;
}

double get(int n){
	double l = 0.0,r = 1.0;
	if(n==1)return 1.0;
	rep(_,50){
		double m0 = l + (r-l)/3.0;
		double m1 = l + (r-l)/3.0 * 2;
		if(get(m0,n)<get(m1,n))l = m0;
		else r = m1;
	}
	return l;
}

int main(){
	
	int n;
	cin>>n;
	
	vector<double> p(n);
	rep(i,n){
		cin>>p[i];
	}
	
	sort(p.begin(),p.end());
	
	if(p.back()==1.0){
		cout<<1.0<<endl;
		return 0;
	}
	double ans = 0.0;
	
	rep(i,n){
		double mul = 1.0,sum = 0.0;
		for(int j=i;j<n;j++){
			mul *= 1.0-p[j];
			sum += p[j] / (1.0-p[j]);
			ans = max(ans,mul*sum);
		}
	}
	
	cout<<fixed<<setprecision(15)<<ans<<endl;
	
    return 0;
}