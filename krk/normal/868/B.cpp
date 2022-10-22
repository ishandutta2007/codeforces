#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

int h, m, s, t1, t2;

int main()
{
	cin >> h >> m >> s >> t1 >> t2;
	if (h == 12) h = 0;
	int tim = h * 3600 + 60 * m + s;
	ld angh = 360.0l / ld(43200) * ld(tim); 
	tim = 60 * m + s;
	ld angm = 360.0l / ld(3600) * ld(tim);
	tim = s;
	ld angs = 360.0l / ld(60) * ld(tim);
	if (t1 == 12) t1 = 0;
	if (t2 == 12) t2 = 0;
	ld angt1 = t1 * ld(30), angt2 = t2 * ld(30);
	if (angt1 > angt2) swap(angt1, angt2);
	int res = int(angt1 < angh && angh < angt2) + int(angt1 < angm && angm < angt2) + int(angt1 < angs && angs < angt2);
	printf("%s\n", (res == 0 || res == 3)? "YES": "NO");
	return 0;
}