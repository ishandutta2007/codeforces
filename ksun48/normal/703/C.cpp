#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	double w, v, u;
	cin >> n >> w >> v >> u;
	double x[n];
	double y[n];
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	double s = u/v;
	double r[n];
	for(int i = 0; i < n; i++){
		r[i] = x[i]-y[i]/s;
	}
	double a = r[0];
	double b = 0.0;
	for(int i = 0; i < n; i++){
		a = min(a,r[i]);
		b = max(b,r[i]);
	}
	if(a >= -0.000000001){
		printf("%.10lf\n", w/u);
	} else {
		double c = w/u+b/v;
		printf("%.10lf\n", c);
	}
}