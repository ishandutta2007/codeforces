#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define first fi
#define second se
#define SET(p,n) memset(p, n, sizeof(p));

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	string s;
	cin >> s;
	int c = 0, n;

	n = -1;
	while ((n = s.find("Danil", ++n)) != string::npos)
		c++;
	n = -1;
	while ((n=s.find("Olya", ++n)) != string::npos)
		c++;
	n = -1;
	while ((n=s.find("Slava", ++n)) != string::npos)
		c++;
	n = -1;
	while ((n=s.find("Ann", ++n)) != string::npos)
		c++;
	n = -1;
	while ((n=s.find("Nikita", ++n)) != string::npos)
		c++;
	n = -1;

	if (c == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}