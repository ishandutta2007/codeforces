#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int b, g, n;
	cin >> b >> g >> n;
	b = min(b, n);
	g = min(g, n);
	cout << b + g - n + 1 << '\n';
}