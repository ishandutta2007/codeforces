#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxd = 10;
const int Inf = 1000000000;

int t;
int need[Maxd];
int has[Maxd];
int res = Inf;

int Conv(int x) 
{ 
	if (x == 9) x = 6;
	else if (x == 5) x = 2;
	return x; 
}

void Take(int x)
{
	while (x) {
		need[Conv(x % 10)]++;
		x /= 10;
	}
}

int main()
{
	scanf("%d", &t); Take(t);
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) has[Conv(s[i] - '0')]++;
	for (int i = 0; i < Maxd; i++) if (need[i])
		res = min(res, has[i] / need[i]);
	printf("%d\n", res);
	return 0;
}