// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 1010, maxm = 1000010;

int n, m, q, ax, ay, bx, by, l, c, lst, tmp;
int al[maxn][maxn], ar[maxn][maxn];

char s[10000010];

void reads(int &l, int &r) {
	char c = getchar();
	while (c == ' ' || c == '\n') c = getchar();
	l = ++lst, r = l - 1;
	while (c != ' ' && c != '\n') {
		s[++r] = c;
		c = getchar();
	}
	lst = r;
}

void prints(int l, int r) {
	for (int i = l; i <= r; i++)
		putchar(s[i]);
}

struct node {
	int x, y;
	node () {}
	node (int a, int b) { x = a, y = b; }
};
node au, bu, as, bs;
node ex[maxn][maxn], ey[maxn][maxn];

struct pair {
	node a, b;
	pair () {}
	pair (node x, node y) { a = x, b = y; }
};
std::vector < pair > todo_ex, todo_ey;

node lead_to(int x, int y) {
	node u = node(0, 0);
	while (x--) u = ex[u.x][u.y];
	while (y--) u = ey[u.x][u.y];
	return u;
}

void print() {
	node u(0, 0);
	for (int i = 1; i <= n; i++) {
		node v = u = ex[u.x][u.y];
		for (int j = 1; j <= m; j++) {
			v = ey[v.x][v.y];
//			printf("> %d %d\n", v.x, v.y);
			prints(al[v.x][v.y], ar[v.x][v.y]);
			putchar(' ');
		}
		putchar('\n');
	}
//	for (int i = 0; i <= n; i++)  {
//		for (int j = 0; j <= m; j++)
//			printf("(%d, %d)", ex[i][j].x, ex[i][j].y);
//		putchar('\n');
//	}
//	for (int i = 0; i <= n; i++)  {
//		for (int j = 0; j <= m; j++)
//			printf("(%d, %d)", ey[i][j].x, ey[i][j].y);
//		putchar('\n');
//	}
}

void swap_ex(node a, node b) {
//	printf("swap [%d][%d](%d,%d) <-> [%d][%d](%d,%d)\n",
//			a.x, a.y, ex[a.x][a.y].x, ex[a.x][a.y].y, 
//			b.x, b.y, ex[b.x][b.y].x, ex[b.x][b.y].y);
	todo_ex.push_back(pair(a, b));
//	std::swap(ex[a.x][a.y], ex[b.x][b.y]);
}

void swap_ey(node a, node b) {
//	printf("swap [%d][%d](%d,%d) <-> [%d][%d](%d,%d)\n",
//			a.x, a.y, ey[a.x][a.y].x, ey[a.x][a.y].y, 
//			b.x, b.y, ey[b.x][b.y].x, ey[b.x][b.y].y);
	todo_ey.push_back(pair(a, b));
//	std::swap(ey[a.x][a.y], ey[b.x][b.y]);
}

int main() {
//	freopen("INPUT", "r", stdin);

	n = read(), m = read(), q = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			reads(al[i][j], ar[i][j]);
		}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) {
			ex[i][j] = node(i + 1, j);
			ey[i][j] = node(i, j + 1);
		}

	for (int t = 1; t <= q; t++) {
		ax = read(), ay = read();
		bx = read(), by = read();
		l = read(), c = read();
		as = lead_to(ax - 1, ay - 1);
		bs = lead_to(bx - 1, by - 1);
//		puts("=== 1 ===");
		au = as, bu = bs;
		for (int i = 1; i <= l; i++) {
//			printf("au : (%d,%d) -> (%d,%d)\n", au.x, au.y, ex[au.x][au.y].x, ex[au.x][au.y].y);
//			printf("bu : (%d,%d) -> (%d,%d)\n", bu.x, bu.y, ex[bu.x][bu.y].x, ex[bu.x][bu.y].y);
			au = ex[au.x][au.y];
			bu = ex[bu.x][bu.y];
			swap_ey(au, bu);
		}
//		puts("=== 2 ===");
		au = as, bu = bs;
		for (int i = 1; i <= c; i++) {
//			printf("au : (%d,%d) -> (%d,%d)\n", au.x, au.y, ey[au.x][au.y].x, ey[au.x][au.y].y);
//			printf("bu : (%d,%d) -> (%d,%d)\n", bu.x, bu.y, ey[bu.x][bu.y].x, ey[bu.x][bu.y].y);
			au = ey[au.x][au.y];
			bu = ey[bu.x][bu.y];
			swap_ex(au, bu);
		}
//		puts("=== 3 ===");
		au = as, bu = bs;
		for (int i = 1; i <= l; i++) {
//			printf("au : (%d,%d) -> (%d,%d)\n", au.x, au.y, ex[au.x][au.y].x, ex[au.x][au.y].y);
//			printf("bu : (%d,%d) -> (%d,%d)\n", bu.x, bu.y, ex[bu.x][bu.y].x, ex[bu.x][bu.y].y);
			au = ex[au.x][au.y];
			bu = ex[bu.x][bu.y];
		}
		for (int i = 1; i <= c; i++) {
//			printf("au : (%d,%d) -> (%d,%d)\n", au.x, au.y, ey[au.x][au.y].x, ey[au.x][au.y].y);
//			printf("bu : (%d,%d) -> (%d,%d)\n", bu.x, bu.y, ey[bu.x][bu.y].x, ey[bu.x][bu.y].y);
			au = ey[au.x][au.y];
			bu = ey[bu.x][bu.y];
			swap_ex(au, bu);
		}
//		puts("=== 4 ===");
		au = as, bu = bs;
		for (int i = 1; i <= c; i++) {
//			printf("au : (%d,%d) -> (%d,%d)\n", au.x, au.y, ey[au.x][au.y].x, ey[au.x][au.y].y);
//			printf("bu : (%d,%d) -> (%d,%d)\n", bu.x, bu.y, ey[bu.x][bu.y].x, ey[bu.x][bu.y].y);
			au = ey[au.x][au.y];
			bu = ey[bu.x][bu.y];
		}
		for (int i = 1; i <= l; i++) {
//			printf("au : (%d,%d) -> (%d,%d)\n", au.x, au.y, ex[au.x][au.y].x, ex[au.x][au.y].y);
//			printf("bu : (%d,%d) -> (%d,%d)\n", bu.x, bu.y, ex[bu.x][bu.y].x, ex[bu.x][bu.y].y);
			au = ex[au.x][au.y];
			bu = ex[bu.x][bu.y];
			swap_ey(au, bu);
		}
		for (std::vector < pair > ::iterator it = todo_ex.begin();
				it != todo_ex.end();
				it++)
			std::swap(ex[it->a.x][it->a.y], ex[it->b.x][it->b.y]);
		for (std::vector < pair > ::iterator it = todo_ey.begin();
				it != todo_ey.end();
				it++)
			std::swap(ey[it->a.x][it->a.y], ey[it->b.x][it->b.y]);
		todo_ex.clear();
		todo_ey.clear();
	}
	print();

	return 0;
}