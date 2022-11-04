#include <bits/stdc++.h>
using namespace std;

pair<double,double> go (double a, double b, double l){
	double x[] = {a-l, a+l};
	double y[] = {b-l, b+l};
	double mini = x[0]*y[0];
	double maxi = x[0]*y[0];
	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++){
			mini = min(mini, x[i]*y[j]);
			maxi = max(maxi, x[i]*y[j]);
		}
	return pair<double,double>(mini,maxi);
}

int main(){
	double a,b,c,d; cin >> a >> b >> c >> d;
	double lo=0.0, hi=1e10;
	for (int rep=1; rep<=300; rep++){
		double mid = (lo + hi) / 2;
		pair<double,double> f0 = go(a,d,mid);
		pair<double,double> f1 = go(b,c,mid);
		if (max(f0.first,f1.first) <= min(f0.second,f1.second))
			hi = mid;
		else
			lo = mid;
	}
	cout << fixed << setprecision(10) << (lo+hi)/2 << endl;
	return 0;
}