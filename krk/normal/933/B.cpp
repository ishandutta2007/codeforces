#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll p;
int k;
vector <int> res;

int main()
{
	cin >> p >> k;
	while (p)
		if (p > 0) {
			ll dv = p / k;
			res.push_back(p % k);
			p = -dv;
		} else {
			ll dv = (-p) / k;
			if ((-p) % k) dv++;
			res.push_back(dv * k + p);
			p = dv;
		}
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}