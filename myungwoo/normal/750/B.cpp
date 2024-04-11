#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc secondd
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

int Q;

void no(){ puts("NO"); exit(0); }

int main()
{
	int h = 0;
	for (cin >> Q;Q--;){
		int a; string s;
		cin >> a >> s;
		if (s == "North"){
			h -= a;
			if (h < 0) no();
		}
		else if (s == "South"){
			h += a;
			if (h > 20000) no();
		}else if (h == 0 || h == 20000) no();
	}
	puts(h == 0 ? "YES" : "NO");
}