#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxm = 1005;
const int Inf = 2000000000;

int m, k;
int d[Maxm];
int s[Maxm];
int tim;
int fuel;
int mx;

int main()
{
	scanf("%d %d", &m, &k);
	for (int i = 0; i < m; i++) 
		scanf("%d", &d[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &s[i]);
	for (int i = 0; i < m; i++) {
		fuel += s[i]; mx = max(mx, s[i]);
		if (fuel < d[i]) {
			int tims = (d[i] - fuel) / mx + ((d[i] - fuel) % mx > 0);
			tim += tims * k;
			fuel += mx * tims;
		}
		tim += d[i];
		fuel -= d[i];
	}
	printf("%d\n", tim);
	return 0;
}