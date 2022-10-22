#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

const int Maxt = 105;

string s;
int nb, ns, nc;
int pb, ps, pc;
ll r;
ll res;

int main()
{
	cin >> s;
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;
	for (int i = 0; i < Maxt; i++) {
		ll cost = 0ll;
		for (int j = 0; j < s.length(); j++)
			if (s[j] == 'B') if (nb) nb--;
							 else cost += pb;
			else if (s[j] == 'S') if (ns) ns--;
								  else cost += ps;
			else if (s[j] == 'C') if (nc) nc--;
								  else cost += pc;
		if (cost > r) break;
		res++; r -= cost;
	}
	ll cost = 0ll;
	for (int j = 0; j < s.length(); j++)
		if (s[j] == 'B') cost += pb;
		else if (s[j] == 'S') cost += ps;
		else if (s[j] == 'C') cost += pc;
	res += r / cost;
	printf("%I64d\n", res);
	return 0;
}