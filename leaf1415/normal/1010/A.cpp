#include <iostream>
#include <stdio.h>

using namespace std;

int n;
double m;
double a[1005], b[1005];

bool check(double x)
{
	double fuel = x, need;
	for(int i = 1; i <= n; i++){
		if(i >= 2){
			need = (m+fuel) / b[i];
			if(need > fuel) return false;
			fuel -= need;
		}
		need = (m+fuel) / a[i];
		if(need > fuel) return false;
		fuel -= need;
	}
	need = (m+fuel) / b[1];
	if(need > fuel) return false;
	fuel -= need;
	return true;
}

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	double ub = 1e9+10, lb = 0, mid;
	for(int i = 0; i < 100; i++){
		mid = (ub + lb) / 2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	double ans = (ub + lb) / 2;
	if(ans > 1e9+5){
		cout << -1 << endl;
		return 0;
	}
	
	printf("%.11f\n", ans);
	return 0;
}