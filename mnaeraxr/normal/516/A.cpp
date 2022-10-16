#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <string.h>

using namespace std;

#define MP make_pair
#define SZ(x) ((int)((x).size()))
#define DB(x) cout << #x << "=" << x << endl

typedef long long int64;
typedef vector<int> vi;
typedef pair<int64,int64> pii;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-7;
const int MAXN = (int)1e5 + 10;

char S[100];
vector<char> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	cin >> S;
	for (int i = 0; i < n; ++i)
	{
		int val = S[i] - '0';
		if (val <= 1) continue;
		if (val == 2) ans.push_back('2');
		if (val == 3) ans.push_back('3');
		if (val == 4){
			ans.push_back('3');
			ans.push_back('2');
			ans.push_back('2');
		}
		if (val == 5)ans.push_back('5');
		if (val == 6){
			ans.push_back('5');
			ans.push_back('3');
		}
		if (val == 7) ans.push_back('7');
		if (val == 8){
			ans.push_back('7');
			ans.push_back('2');
			ans.push_back('2');
			ans.push_back('2');
		}
		if (val == 9)
		{
			ans.push_back('7');
			ans.push_back('3');
			ans.push_back('3');
			ans.push_back('2');
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = SZ(ans) - 1; i >= 0; --i)
		cout << ans[i];
	cout << endl;
}