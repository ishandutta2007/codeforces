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

#define maxN ()

main()
{
	ifstream fin ("input.txt");
	ofstream fout ("output.txt");

	string x; fin >> x;
	int r; fin >> r;
	fout << ((x == "front") ^ (r == 1) ? "R" : "L") << endl;

	return 0;
}