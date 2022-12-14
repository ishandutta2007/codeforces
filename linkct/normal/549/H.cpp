#include <iostream>
#include <cstdio>
using namespace std;

double a, b, c, d;

inline double sgn(int x){return x ? 1 : -1;}
bool check(double T){
	int i; double l1, l2, r1, r2;
	for(i = 0; i < 16; ++ i){
		l1 = min(a * d, (a + sgn(i & 1) * T) * (d + sgn(i & 2) * T)), r1 = max(a * d, (a + sgn(i & 1) * T) * (d + sgn(i & 2) * T));
		l2 = min(b * c, (b + sgn(i & 4) * T) * (c + sgn(i & 8) * T)), r2 = max(b * c, (b + sgn(i & 4) * T) * (c + sgn(i & 8) * T));
		if(max(l1, l2) < min(r1, r2)) return true;
	}
	return false;
}
int main(){
	cin >> a >> b >> c >> d;
	double l = 0.000, r = 1e9, mid;
	for(int i = 1; i <= 100; ++ i){
		mid = (l + r) / 2.000;
		if(check(mid)) r = mid;
		else l = mid;
	}
	printf("%.15f\n", r);
	return 0;
}