#include<bits/stdc++.h>
using namespace std;
long long a,b;
int main() {
	cin >> a >> b;
	if(b >= 2*a) {
		long long d = b/a;
		cout << "YES\n";
		for(int i = 1;i < a;++i)
			cout << d << ' ',b -= d;
		cout << b << "\n1\n";
	}
	else {
		cout << "NO\n";
	}
	return 0;
}