/**
 *    author:  Mohamed.Abo_Okail
 *    created: 23/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n, x; cin >> n >> x;
	vector <ll> a(n), b(n);
	ll ans1 = 0, ans2 = 0, sum = 0, f = 0;
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	for (int i = 0; i < n; i++) { cin >> b[i]; }
	for (int i = 0; i < n; i++) {
		sum += b[i];
		ans1 += max((a[i] - sum * x), f);
	} sum = 0;
	for (int i = (n - 1); i >= 0; i--) {
		sum += b[i];
		ans2 += max((a[i] - sum * x), f);
	}
	if(ans1 > ans2) {
		cout << "Limak" << endl;
	}
	else if(ans2 > ans1) {
		cout << "Radewoosh" << endl;
	}
	else {
		cout << "Tie" << endl;
	}
}