#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , x , y;
	string s;

	cin >> n >> x >> y >> s;

	s.resize(unique(s.begin() , s.end()) - s.begin());

	n = s.size();

	int t = 0;
	for(int i = 0; i < n; i++)
		t += (s[i] == '0');

	if(!t)
		return cout << 0 << endl , 0;

	if(x >= y)
		cout << 1LL * y * t << endl;
	else
		cout << 1LL * (t - 1) * x + 1LL * y << endl;

}