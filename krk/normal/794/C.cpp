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

const int Maxl = 300005;

char tmp[Maxl];
string A, B, C;
int al, ar;
int bl, br;
int cl, cr;

void Read(string &s)
{
	scanf("%s", tmp); s = tmp;
}

int main()
{
	Read(A); Read(B);
	sort(A.begin(), A.end()); sort(B.begin(), B.end());
	C = string(A.size(), '?');
	al = 0; ar = (A.size() + 1) / 2 - 1;
	bl = A.size() - A.size() / 2; br = A.size() - 1;
	cl = 0; cr = A.size() - 1;
	bool fir = true;
	for (int i = 0; i < A.size(); i++) {
		if (fir) if (br < bl || A[al] < B[br]) C[cl++] = A[al++];
				 else C[cr--] = A[ar--];
		else if (B[br] > A[al]) C[cl++] = B[br--];
			 else C[cr--] = B[bl++];
		fir = !fir;
	}
	printf("%s\n", C.c_str());
	return 0;
}