#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll INF = 1e18+3;
#define maxn 1000100
int klucze[30];
int main()
{
	string s;
	boost;
	int n;
	cin >> n;
	cin >> s;
	int wyn =0;
	for (int i=0; i<(2 *n - 2); ++i)
	{
		if (!(i & 1))
		{
			klucze[s[i] - 'a']++;
		} 
		else
		{
			if (klucze[s[i] - 'A'] > 0) klucze[s[i] - 'A']--;
			else ++wyn;
		}
		
	}
	cout << wyn << endl;
}