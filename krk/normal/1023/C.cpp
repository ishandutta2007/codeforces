#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, k;
string s;
bool tk[Maxn];

int main()
{
	cin >> n >> k;
	cin >> s;
	vector <int> S;
	for (int i = 0; i < s.length() && k > 0; i++)
		if (s[i] == '(') S.push_back(i);
		else if (!S.empty()) {
			tk[S.back()] = tk[i] = true;
			k -= 2;
			S.pop_back();
		}
	for (int i = 0; i < s.length(); i++)
		if (tk[i]) printf("%c", s[i]);
	printf("\n");
	return 0;
}