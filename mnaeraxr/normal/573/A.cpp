#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int tmp = -1;


	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		while (v % 2 == 0) v /= 2;
		while (v % 3 == 0) v /= 3;

		if (tmp == -1) tmp = v;
		else{
			if (tmp != v){
				 cout << "No" << endl;
				 exit(0);
			}
		}
	}
	cout << "Yes" << endl;
}