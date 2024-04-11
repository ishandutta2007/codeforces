#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int n;
double r;
double x[1005], y[1005];

int main(void)
{
	cin >> n >> r;
	for(int i = 0; i < n; i++) cin >> x[i];
	
	double t, u;
	for(int i = 0; i < n; i++){
		t = r;
		for(int j = 0; j < i; j++){
			u = 4*r*r - (x[i] - x[j])*(x[i]-x[j]);
			if(u < 0) continue;
			if(u > 0) u = sqrt(u);
			t = max(t, y[j]+u);
		}
		y[i] = t;
	}
	
	for(int i = 0; i < n; i++){
		printf("%.9f", y[i]);
		if(i < n-1) cout << " ";
	}
	cout << endl;
	return 0;
}