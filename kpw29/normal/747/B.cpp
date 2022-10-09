#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <int, int> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf =1e9+9;
const ll mod = 1e9+9;
const ll MOD = 1e9+696969;
int n;
typedef vector <int> poly;
poly A, B;
int zn[300];
char reff[300];
int ile[4];

int main()
{
	zn['C'] = 0; zn['A'] =1; zn['G'] =2; zn['T'] = 3;
	reff[0] = 'C'; reff[1] = 'A'; reff[2] = 'G'; reff[3] = 'T';
	ile[4] = 31289;
	boost;
	string s;
	cin >> n;
	cin >> s;
	if (n % 4 != 0) OUT("===");
	FOR(i, 0, n-1) {
		if (s[i] != '?') ile[zn[s[i]]]++;
	}

	FOR(i, 0, n-1) {

		if (s[i] == '?') {
			int M = 4; 
			char zz;
			FOR(j, 0, 3)
			  if (ile[j] < ile[M]) {
			  	M = j;
			  	zz = reff[j];
			  }	
			  //cout << M << endl;
			  s[i] = reff[M];
		 		ile[zn[s[i]]]++;
		
		}
	}
	
	if (ile[0] == ile[1] && ile[0] == ile[2] && ile[0] == ile[3])cout << s;
	else cout << "===";
}