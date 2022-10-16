#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000010;

char n1[maxn];
char n2[maxn];

int main()
{
	scanf("%s%s", n1, n2);
	int len1 = strlen(n1);
	int len2 = strlen(n2);
	int pnt1 = 0;
	int pnt2 = 0;

	while (pnt1 + 1 < len1 && n1[pnt1] == '0')
		++pnt1;

	while (pnt2 + 1 < len2 && n2[pnt2] == '0')
		++pnt2;

	if (len1 - pnt1 != len2 - pnt2){
		if (len1 - pnt1 > len2 - pnt2)
			putchar('>');
		else
			putchar('<');
	}
	else{
		while (pnt1 < len1){
			if (n1[pnt1] != n2[pnt2]){
				if (n1[pnt1] < n2[pnt2])
					putchar('<');
				else
					putchar('>');
				return 0;
			}
			++pnt1; ++pnt2;
		}
		putchar('=');
	}

	return 0;
}