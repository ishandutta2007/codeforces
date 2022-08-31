#include<iostream>
#include<iomanip>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	double p[n];
	for(int i = 0; i < n; i++) cin >> p[i];
	double a = 0;
	double ans = 0;
	for(int i = 0; i < n; i++){
		a += 1.0;
		a *= p[i];
		ans += a;
	}
	ans *= 2;
	for(int i = 0; i < n; i++) ans -= p[i];
	cout << fixed << setprecision(10) << ans << endl;
}