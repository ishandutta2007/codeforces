#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	string a, b;
	cin >> a >> b;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());

	int n = (int)a.length();

	int ba = 0, ea = (n + 1) / 2;
	int bb = 0, eb = n / 2;

	string X = "", Y = "";

	for (int i = 0; i < n; ++i){
		if (i % 2 == 0){
			if (a[ba] < b[bb])
				X += a[ba++];
			else
				Y += a[--ea];
		}
		else{
			if (a[ba] < b[bb])
				X += b[bb++];
			else
				Y += b[--eb];
		}
	}

	reverse(Y.begin(), Y.end());
	cout << X << Y << endl;


	return 0;
}