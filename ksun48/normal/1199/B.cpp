#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ld a, b;
	cin >> a >> b;
	ld c = sqrt(a*a + b*b);
	ld v = c * (c/2) / a;
	cout << fixed << setprecision(20) << v - a << '\n';
}