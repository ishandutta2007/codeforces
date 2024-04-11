#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long double ld;

const int Maxn = 200005;
const int Maxt = 70;

int n, T;
ii seq[Maxn];

ld getLow()
{
	ld sum = 0;
	ld am = 0;
	for (int i = 0; i < n; i++)
		if ((sum + ld(seq[i].first) * seq[i].second) / (am + seq[i].second) <= T) {
			sum += ld(seq[i].first) * seq[i].second;
			am += seq[i].second;
		} else {
			ld x = (T * am - sum) / (ld(seq[i].first) - T);
			return am + x;
		}
	return am;
}

ld getHigh()
{
	ld sum = 0;
	ld am = 0;
	for (int i = n - 1; i >= 0; i--)
		if ((sum + ld(seq[i].first) * seq[i].second) / (am + seq[i].second) >= T) {
			sum += ld(seq[i].first) * seq[i].second;
			am += seq[i].second;
		} else {
			ld x = (T * am - sum) / (ld(seq[i].first) - T);
			return am + x;
		}
	return am;
}

int main()
{
	scanf("%d %d", &n, &T);
	ld tot = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i].second);
		tot += seq[i].second;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &seq[i].first);
	sort(seq, seq + n);
	cout << fixed << setprecision(13) << min(getLow(), getHigh()) << endl;
	return 0;
}