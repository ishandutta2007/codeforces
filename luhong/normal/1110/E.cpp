#include <cstdio>
#include <algorithm>
#define MN 101000

int a[MN], b[MN], c[MN], d[MN]; 

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for(int i = 1; i < n; i++) c[i] = a[i + 1] - a[i];
	for(int i = 1; i < n; i++) d[i] = b[i + 1] - b[i];
	std::sort(c + 1, c + n); std::sort(d + 1, d + n);
	bool ok = 1;
	if(a[1] != b[1] || a[n] != b[n]) ok = 0;
	for(int i = 1; i < n; i++) if(c[i] != d[i]) ok = 0;
	if(ok) puts("Yes");
	else puts("No");
}
//