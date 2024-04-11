#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 t, a, b;
	cin >> t >> a >> b;

	if (t == 1){
		if (a == 1 && b == 1){
			cout << "inf" << endl;
		}
		else if (a == 1){
			cout << 0 << endl;			
		}
		else{

			int ans = 0;

			int64 x = b;
			while (x % a == 0 && x > a)
				x /= a;
			if (x == a) ++ans;

			int64 cur = 0;
			while (b && cur <= a){
				cur += b % a;
				b /= a;
			}
			if (cur == a) ++ans;

			cout << ans << endl;
		}
	}
	else{
		if (a == b){
			int ans = 1;
			if (t == a) ++ans;
			cout << ans << endl;
		}
		else if (a == 1){
			cout << 0 << endl;
		}
		else{
			int64 x = 1;
			int64 v = 0;
			while (b && v <= a){
				int64 cur = b % a;
				b /= a;
				v += x * cur;
				x *= t;
			}

			if (v == a)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}

	return 0;
}