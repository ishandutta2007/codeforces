//

#include <algorithm>
#include <iostream>
#include <fstream>
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

//#define int long long
#define eps 10e-8
#define sqr(x) ((x) * (x))
#define prec(x) fixed << setprecision (x)
#define equal(a,b) ((bool) (abs ((a) - (b) < eps))) 
#define dis(x1,y1,x2,y2) (sqrt ((sqr ((x1) - (x2)))+(sqr ((y1) - (y2)))))

using namespace std;

#define maxN (50 + 1)

int n, m;
int a[maxN][maxN];
int t[3];
int tmp[3];

bool ok ()
{	
	sort (tmp, tmp + 3);
	for (int i = 0; i < 3; i++)
		if (t[i] != tmp[i])
			return 0;
	return 1;
}

main()
{
	ifstream fin ("input.txt");
	ofstream fout ("output.txt");

	fin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			fin >> a[i][j];
	for (int i = 0; i < 3; i++)
		fin >> t[i];

	sort (t, t + 3);

	int res = 0;
	for (int x = 1; x < n - 1; x++)
		for (int y = x + 1; y < n; y++)
		{
			memset (tmp, 0, sizeof tmp);
			for (int i = 0; i < x; i++)
				for (int j = 0; j < m; j++)
					tmp[0] += a[i][j];
			for (int i = x; i < y; i++)
				for (int j = 0; j < m; j++)
					tmp[1] += a[i][j];
			for (int i = y; i < n; i++)
				for (int j = 0; j < m; j++)
					tmp[2] += a[i][j];

	//		cerr << x << ' ' << y << endl;
	//		for (int i = 0; i < 3; i++)
	//			cerr << tmp[i] << ' ';
	//		cerr << endl;
			res += ok ();
		}

	//cerr << endl;
		
	for (int x = 1; x < m - 1; x++)
		for (int y = x + 1; y < m; y++)
		{
			memset (tmp, 0, sizeof tmp);
			for (int i = 0; i < x; i++)
				for (int j = 0; j < n; j++)
					tmp[0] += a[j][i];
			for (int i = x; i < y; i++)
				for (int j = 0; j < n; j++)
					tmp[1] += a[j][i];
			for (int i = y; i < m; i++)
				for (int j = 0; j < n; j++)
					tmp[2] += a[j][i];

	//		cerr << x << ' ' << y << endl;
	//		for (int i = 0; i < 3; i++)
	//			cerr << tmp[i] << ' ';
	//		cerr << endl;
			res += ok ();
		}

	fout << res << endl;

	return 0;
}