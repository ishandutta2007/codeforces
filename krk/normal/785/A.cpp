#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

map <string, int> M;
int n;
char str[50];
int res;

int main()
{
	M["Tetrahedron"] = 4;
	M["Cube"] = 6;
	M["Octahedron"] = 8;
	M["Dodecahedron"] = 12;
	M["Icosahedron"] = 20;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", str);
		res += M[str];
	}
	printf("%d\n", res);
	return 0;
}