#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	double q[n];
	for(int i = 0; i < n; i++){
	 cin >> q[i];
	q[i] /= 100.0;
	q[i] = 1.0 - q[i];
	}
	double ans = n;
	double t[n];
	for(int i = 0; i < n; i++) t[i] = q[i];
	for(int qz = 0; qz < 1000000; qz++){
		double prob = 1.0;
		for(int i = 0; i < n; i++){
			prob *= (1.0-t[i]);
		}
		ans += (1.0-prob);
		int m = -1;
		double c = -1.0;
		for(int i = 0; i < n; i++){
			double r = (1.0-t[i]*q[i])/(1.0-t[i]);
			if(r > c){
				c = r;
				m = i;
			}
		}
		t[m] *= q[m];
	}
	printf("%.9f\n", ans);
}