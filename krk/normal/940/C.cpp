#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;
vector <char> lets;

int main()
{
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < n; i++)
		lets.push_back(s[i]);
	sort(lets.begin(), lets.end()); lets.erase(unique(lets.begin(), lets.end()), lets.end());
	if (k > n) {
		string t(k, '.');
		for (int i = 0; i < n; i++)
			t[i] = s[i];
		for (int i = n; i < k; i++)
			t[i] = lets[0];
		cout << t << endl;
	} else {
		string t(k, '.');
		int pnt = k - 1;
		while (s[pnt] == lets.back()) pnt--;
		for (int i = 0; i < pnt; i++)
			t[i] = s[i];
		int ind = 0;
		while (s[pnt] != lets[ind]) ind++;
		t[pnt] = lets[ind + 1];
		for (int i = pnt + 1; i < k; i++)
			t[i] = lets[0];
		cout << t << endl;
	}
	return 0;
}