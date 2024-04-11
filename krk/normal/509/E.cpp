#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

typedef long double ld;

const string vow = "IEAOUY";
const int Maxn = 500005;

char str[Maxn];
int slen;
ld sum[Maxn];
int vals[Maxn];
ld res;

int main()
{
	scanf("%s", str + 1); slen = strlen(str + 1); 
	for (int i = 1; i <= slen; i++)
		sum[i] = sum[i - 1] + 1.0l / ld(i);
	for (int i = 1; i <= slen; i++) {
		vals[i] = vals[i - 1] + (vow.find(str[i]) != string::npos);
		res += sum[i] * vals[i];
		if (i < slen) res -= sum[slen - i] * vals[i];
	}
	cout << fixed << setprecision(7) << res << endl;
	return 0;
}