#include <cstdio>
using namespace std;

const int Maxn = 22;
const int Maxt = 60;

int n, V;
int a[Maxn];
int sum;
int b[Maxn];

bool Enough(double V)
{
	double x = V / double(sum);
	for (int i = 0; i < n; i++)
		if (a[i] * x > b[i]) return false;
	return true;
}

int main()
{
	scanf("%d %d", &n, &V);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); sum += a[i];
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	double lef = 0.0, rig = V;
	for (int i = 0; i < Maxt; i++) {
		double mid = (lef + rig) / 2.0;
		if (Enough(mid)) lef = mid;
		else rig = mid;
	}
	printf("%.9lf\n", lef);
	return 0;
}