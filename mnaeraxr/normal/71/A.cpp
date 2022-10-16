/*
	Author:	MarX
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define MAX 100000

int main()
{
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		if (s.length() <= 10) cout << s << endl;
		else cout << s[0] << s.length() - 2 << s[s.length() - 1] << endl;
	}
}