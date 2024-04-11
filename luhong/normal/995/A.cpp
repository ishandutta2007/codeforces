#include <iostream>
#include <cstdio>
#define MN 55

int a[MN], b[MN], c[MN], d[MN];
int I[21000], R[21000], C[21000], tot = 0;
int n, k; 
int x, y;

void move()
{
	int w = (x == 2 ? b[y] : c[y]);
	if(!w) return;
	if(x == 2) b[y] = 0; else c[y] = 0;
	if(x == 3 && y == 1) x = 2, y = 1; 
	else if(x == 3) x = 3, y--; 
	else if(x == 2 && y == n) x = 3, y = n; 
	else if(x == 2) x = 2, y++;
	int X = x, Y = y;
	move();
	++tot, I[tot] = w, R[tot] = X, C[tot] = Y;
	if(X == 2) b[Y] = w; else c[Y] = w;
	if(X == 2 && w == a[Y]) ++tot, I[tot] = w, R[tot] = 1, C[tot] = Y, b[Y] = 0;
	if(X == 3 && w == d[Y]) ++tot, I[tot] = w, R[tot] = 4, C[tot] = Y, c[Y] = 0;
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &d[i]);
	for(int i = 1; i <= n; i++) if(b[i] && b[i] == a[i]) ++tot, I[tot] = b[i], R[tot] = 1, C[tot] = i, b[i] = 0;
	for(int i = 1; i <= n; i++) if(c[i] && c[i] == d[i]) ++tot, I[tot] = c[i], R[tot] = 4, C[tot] = i, c[i] = 0;
	bool ok = 0;
	for(int i = 1; i <= n; i++) if(!b[i]) ok = 1;
	for(int i = 1; i <= n; i++) if(!c[i]) ok = 1;
	if(!ok) return 0 * puts("-1");
	for(int i = 1; i <= n; i++) x = 2, y = i, move();
	for(int i = n; i >= 1; i--) x = 3, y = i, move();
	for(int i = 1; i <= n; i++) x = 2, y = i, move();
	for(int i = n; i >= 1; i--) x = 3, y = i, move();
	printf("%d\n", tot);
	for(int i = 1; i <= tot; i++) printf("%d %d %d\n", I[i], R[i], C[i]);
}