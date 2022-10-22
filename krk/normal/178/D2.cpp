#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int Maxn = 9;

int n;
int sum;
map <int, int> lft;
int a[Maxn][Maxn];
bool found;

void Print()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			printf("%d%c", a[i][j], j + 1 < n? ' ': '\n');
}

void Go3(int r, int c)
{
	if (r == n) { Print(); found = true; }
	else for (map <int, int>::iterator it = lft.begin(); it != lft.end() && !found; it++) if (it->second) {
			it->second--; a[r][c] = it->first;
			if (c == 2 && a[r][0] + a[r][1] + a[r][2] != sum ||
				r == 2 && a[0][c] + a[1][c] + a[2][c] != sum ||
				r == 2 && c == 0 && a[0][2] + a[1][1] + a[2][0] != sum ||
				r == 2 && c == 2 && a[0][0] + a[1][1] + a[2][2] != sum) { a[r][c] = 0; it->second++; continue; }
			if (c == 1) {
				int need = sum - a[r][0] - a[r][1];
				if (!lft.count(need) || !lft[need]) { a[r][c] = 0; it->second++; continue; }
			}
			if (r == 1) {
				int need = sum - a[0][c] - a[1][c];
				if (!lft.count(need) || !lft[need]) { a[r][c] = 0; it->second++; continue; }
			}
			if (r == 1 && c == 1) {
				int need1 = sum - a[0][0] - a[1][1];
				int need2 = sum - a[0][2] - a[1][1];
				if (!lft.count(need1) || !lft[need1] || !lft.count(need2) || !lft[need2]) { it->second++; continue; }
			}
			Go3(r + (c + 1) / 3, (c + 1) % 3);
			a[r][c] = 0; it->second++;
		 }
}

void Go4(int r, int c)
{
	if (r == n) { Print(); found = true; }
	else for (map <int, int>::iterator it = lft.begin(); it != lft.end() && !found; it++) if (it->second) {
			it->second--; a[r][c] = it->first;
			if (c == 3 && a[r][0] + a[r][1] + a[r][2] + a[r][3] != sum ||
				r == 3 && a[0][c] + a[1][c] + a[2][c] + a[3][c] != sum ||
				r == 3 && c == 0 && a[0][3] + a[1][2] + a[2][1] + a[3][0] != sum ||
				r == 3 && c == 3 && a[0][0] + a[1][1] + a[2][2] + a[3][3] != sum) { it->second++; continue; }
			if (c == 2) {
				int need = sum - a[r][0] - a[r][1] - a[r][2];
				if (!lft.count(need) || !lft[need]) { it->second++; continue; }
			}
			if (r == 2) {
				int need = sum - a[0][c] - a[1][c] - a[2][c];
				if (!lft.count(need) || !lft[need]) { it->second++; continue; }
			}
			if (r == 2 && c == 1) {
				int need = sum - a[0][3] - a[1][2] - a[2][1];
				if (!lft.count(need) || !lft[need]) { it->second++; continue; }
			}
			if (r == 2 && c == 2) {
				int need = sum - a[0][0] - a[1][1] - a[2][2];
				if (!lft.count(need) || !lft[need]) { it->second++; continue; }
			}
			Go4(r + (c + 1) / 4, (c + 1) % 4);
			it->second++;
		}
}

int main()
{
	scanf("%d", &n);
	if (n <= 2) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]); sum += a[i][j]; 
			}
		sum /= n;
		printf("%d\n", sum);
		Print();
	}
	else {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				int a; scanf("%d", &a); 
				sum += a; lft[a]++;
			}
		sum /= n;
		printf("%d\n", sum);
		found = false;
		if (n == 3) Go3(0, 0);
		else Go4(0, 0);
	}
	return 0;
}