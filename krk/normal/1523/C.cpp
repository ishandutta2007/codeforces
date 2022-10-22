#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n;
int a[Maxn];
vector <int> S;
string res[Maxn];

string toString(int num)
{
	stringstream ss; ss << num;
	string s; ss >> s;
	return s;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		S.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (a[i] == 1) {
				if (S.empty()) res[i] = "";
				else if (res[S.back()].length() == 0) res[i] = toString(a[S.back()]); 
					else res[i] = res[S.back()] + "." + toString(a[S.back()]);
				S.push_back(i);
			} else { 
				while (!S.empty() && a[S.back()] + 1 != a[i])
					S.pop_back();
				res[i] = res[S.back()];
				S.back() = i;
			}
			string ans;
			if (res[i].length() == 0) ans = toString(a[i]);
			else ans = res[i] + "." + toString(a[i]);
			printf("%s\n", ans.c_str());
		}
	}
    return 0;
}