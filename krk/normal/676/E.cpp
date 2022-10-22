#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, k;
int a[Maxn];
bool tr[Maxn];
int miss; 

int toInt(const string &s)
{
	stringstream ss; ss << s;
	int x; ss >> x;
	return x;
}

bool checkSimple()
{
	ll cur = 0;
	for (int i = n; i >= 0; i--) {
		cur *= k; cur += a[i];
	}
	return cur == 0;
}

bool Check()
{
	ll cur = 0;
	for (int i = n; i >= 0; i--) {
		cur *= k; cur += a[i];
		if (cur < -Maxn || cur > Maxn) return false;
	}
	return cur == 0;
}

int main()
{
	scanf("%d %d", &n, &k);
	char tmp[10];
	for (int i = 0; i <= n; i++) {
		scanf("%s", tmp);
		if (tmp[0] != '?') {
			a[i] = toInt(tmp); tr[i] = true;
		} else miss++;
	}
	if (k == 0) // who moves
		if (tr[0])
			if (a[0] == 0) printf("Yes\n");
			else printf("No\n");
		else if ((n + 1 - miss) % 2 != 0) printf("Yes\n");
			 else printf("No\n");
	else if (miss == 0)
			if (k == 1 || k == -1)
				printf("%s\n", checkSimple()? "Yes": "No");
			else printf("%s\n", Check()? "Yes": "No");
	else if ((n + 1) % 2 == 0) printf("Yes\n");
		 else printf("No\n");
	return 0;
}