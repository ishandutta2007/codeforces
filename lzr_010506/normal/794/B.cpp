#include <bits/stdc++.h>
using namespace std;
int n, h;
int main()
{
	cin >> n >> h;
	for(int i = 1; i < n; i ++)
	{
		double g;
		g = sqrt(i / (double)n) * h;
		printf("%.10lf ", g);
	}

	return 0;
}