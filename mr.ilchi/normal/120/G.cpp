//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <set>
#include <map>
#include <fstream>

//#define int long long
#define eps 10e-8
#define sqr(x) ((x) * (x))
#define prec(x) fixed << setprecision (x)
#define equal(a,b) ((bool) (abs ((a) - (b) < eps))) 
#define dis(x1,y1,x2,y2) (sqrt ((sqr ((x1) - (x2)))+(sqr ((y1) - (y2)))))

using namespace std;

#define maxN (100 + 10)

int n, t;
int a[maxN][2];
int b[maxN][2];
int m;
string s[maxN];
int c[maxN];
int f[maxN];
int d[maxN][maxN];

vector <int> guess[maxN];

main()
{
	ifstream fin ("input.txt");
	ofstream fout ("output.txt");

	fin >> n >> t;
	for (int i = 0; i < n; i++)
		fin >> a[i][0] >> b[i][0] >> a[i][1] >> b[i][1];
	fin >> m;
	for (int i = 0; i < m; i++)
		fin >> s[i] >> c[i];

	int rem = m, pointer = 0;
	for (int tmp = 0; rem; tmp = (tmp + 1) % (2 * n))
	{
		//cerr << "turn " << tmp << endl;
		int i = tmp % n;
		int j = tmp / n;
		//cerr << i << ' ' << j << endl;

		int remain = t;
		while (remain && rem)
		{
			//cerr << remain << endl;
			while (f[pointer])
				pointer = (pointer + 1) % m;

			int need = max (1, c[pointer] - (a[i][j] + b[i][1 - j]) - d[i][pointer]);
			if (need > remain)
			//	cerr << "not win " << need << endl,
				d[i][pointer] += remain,
				remain = 0;
			else
			//	cerr << "win " << i << ' ' << s[pointer] << endl,
				f[pointer] = 1,
				guess[i].push_back (pointer),
				rem--,
				remain -= need;
			pointer = (pointer + 1) % m;
		}
	}

	for (int i = 0; i < n; i++)
	{
		fout << guess[i].size() << ' ';
		for (int j = 0; j < guess[i].size(); j++)
			fout << s[guess[i][j]] << ' ';
		fout << endl;
	}

	return 0;
}