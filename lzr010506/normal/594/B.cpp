#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, r, v;
double ans, HF;
bool check(double t)
{
	double x = t * v;
	if(x + sin(x / r) * r >= HF + eps) return 1;
	if(x - sin(x / r) * r >= HF + eps) return 1;
	return 0;
}

int main()
{
	n = read();
	r = read();
	v = read();
	for(int i = 0; i < n; i ++)
	{
		int s, f;
		s = read();
		f = read();
		int L = f - s;
        HF = L / 2.0;
        double l = 0.0, r = HF / v;
        while ((r - l) >= eps)
        {
            double mid = (l + r) / 2.0;
            if (check(mid)) r = mid;
            else l = mid;
        }
        printf("%.12f\n",2 * l);
	}

	return 0;
}