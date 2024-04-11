#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int a, b;

int main()
{
	scanf("%d", &n);
	while (n--) {
		cin >> s >> s;
		if (s == "hard") a++;
		else b++;
	}
	int siz = 1;
	while ((a > siz * siz / 2 || b > (siz * siz + 1) / 2) &&
		   (a > (siz * siz + 1) / 2 || b > siz * siz / 2)) siz++;
	printf("%d\n", siz);
	return 0;
}