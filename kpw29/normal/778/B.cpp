#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false);}
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 5010

int n, m;
int bits[maxn];
bitset <maxn> zbior[5010];
map <string, int> M;
string s;
PPI clause[5010];

int main()
{
	boost;
	cin >> n >> m;
	M["?"] = 0;
	
	FOR(i, 1, n)
	{
		cin >> s;
		//cout << s << endl;
		M[s] = i;
		cin >> s;
		//cout << s << endl;
		cin >> s;	
		if (s[0] != '0' && s[0] != '1')
		{
			clause[i].e1.e1 = M[s];
			cin >> s;
			if (s == "OR") clause[i].e2 = 1;
			else if (s == "XOR") clause[i].e2 = 2;
			else if (s == "AND") clause[i].e2 = 3;
		
			cin >> s;
			clause[i].e1.e2 = M[s];
		}
		else
		{
			for (int j=0; j<s.size(); ++j)
				if (s[j] == '0') zbior[i].set(j+1, 0);
				else zbior[i].set(j+1, 1);
		}
	}
	
	string answer1 = "", answer2 = "";
	FOR(bb, 1, m)
	{
		bits[0] = 0;
		int bzero = 0, bone = 0;
		FOR(i, 1, n)
		{
			if (clause[i].e2 == 0) bits[i] = zbior[i].test(bb);
			else if (clause[i].e2 == 1) bits[i] = (bits[clause[i].e1.e1] | bits[clause[i].e1.e2]);
			else if (clause[i].e2 == 2) bits[i] = (bits[clause[i].e1.e1] ^ bits[clause[i].e1.e2]);
			else if (clause[i].e2 == 3) bits[i] = (bits[clause[i].e1.e1] & bits[clause[i].e1.e2]);
			bzero += bits[i];
		}
		bits[0] = 1;
		FOR(i, 1, n)
		{
			if (clause[i].e2 == 0) bits[i] = zbior[i].test(bb);
			else if (clause[i].e2 == 1) bits[i] = (bits[clause[i].e1.e1] | bits[clause[i].e1.e2]);
			else if (clause[i].e2 == 2) bits[i] = (bits[clause[i].e1.e1] ^ bits[clause[i].e1.e2]);
			else if (clause[i].e2 == 3) bits[i] = (bits[clause[i].e1.e1] & bits[clause[i].e1.e2]);
			bone += bits[i];
		}
		if (bzero > bone)
		{
			answer1 += "0";
			answer2 += "1";
		}
		else if (bzero < bone)
		{
			answer2 += "0";
			answer1 += "1";
		}
		else if (bzero == bone)
		{
			answer2 += "0";
			answer1 += "0";
		}
	}
	
	cout << answer2 << "\n";
	cout << answer1 << "\n";
}