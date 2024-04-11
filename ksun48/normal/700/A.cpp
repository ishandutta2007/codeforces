#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, k;
	double l, v1, v2;
	cin >> n >> l >> v1 >> v2 >> k;
	double c = (n-1)/k + 1; // how many bus tours
	//n forwards, n-1 backwards
	double p = v2/2.0/c+v1-v1/2.0/c;
	double r = l-l/2.0/c+l*v1/2.0/c/v2;
	printf("%.10lf\n", r/p);
}