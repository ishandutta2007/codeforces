#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Maxl = 60;

int n;
string a[Maxn], b[Maxn];
char tmp[Maxl];

void Read(string &s)
{
	scanf("%s", tmp); s = tmp;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		Read(a[i]); Read(b[i]);
		if (a[i] > b[i]) swap(a[i], b[i]);
	}
	int p; scanf("%d", &p);
	string cur = a[p];
	for (int i = 2; i <= n; i++) {
		scanf("%d", &p);
		if (cur < a[p]) cur = a[p];
		else if (cur < b[p]) cur = b[p];
		else { printf("NO\n"); return 0; }
	}
	printf("YES\n");
	return 0;
}