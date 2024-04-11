#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1005;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n;
int x[Maxn], y[Maxn];
vector <int> hor, ver;
vector <vector <bool> > bl, dest;
ll res;

void Process1(int x1, int y1, int x2, int y2)
{
	if (x1 == x2) {
		ver.push_back(x1 - 1); ver.push_back(x1); ver.push_back(x2 + 1);
		hor.push_back(y1 - 1); hor.push_back(y1); hor.push_back(y2); hor.push_back(y2 + 1);
	} else {
		hor.push_back(y1 - 1); hor.push_back(y1); hor.push_back(y2 + 1);
		ver.push_back(x1 - 1); ver.push_back(x1); ver.push_back(x2); ver.push_back(x2 + 1);
	}
}

void Process2(int x1, int y1, int x2, int y2)
{
	if (x1 == x2) {
		int X = lower_bound(ver.begin(), ver.end(), x1) - ver.begin() + 1;
		int Y1 = lower_bound(hor.begin(), hor.end(), y1) - hor.begin() + 1;
		int Y2 = lower_bound(hor.begin(), hor.end(), y2) - hor.begin() + 1;
		for (int i = Y1; i <= Y2; i++) bl[X][i] = true;
	} else {
		int Y = lower_bound(hor.begin(), hor.end(), y1) - hor.begin() + 1;
		int X1 = lower_bound(ver.begin(), ver.end(), x1) - ver.begin() + 1;
		int X2 = lower_bound(ver.begin(), ver.end(), x2) - ver.begin() + 1;
		for (int i = X1; i <= X2; i++) bl[i][Y] = true;
	}
}

void Fill(int x, int y)
{
	if (x < 0 || x > ver.size() || y < 0 || y > hor.size() || bl[x][y] || dest[x][y]) return;
	dest[x][y] = true;
	for (int i = 0; i < Maxd; i++)
		Fill(x + dy[i], y + dx[i]);
}

int main()
{
	scanf("%d", &n);
	x[0] = y[0] = 0;
	for (int i = 1; i <= n; i++) {
		char wh; int len; scanf(" %c %d", &wh, &len);
		if (wh == 'L') { x[i] = x[i - 1] - len; y[i] = y[i - 1]; }
		else if (wh == 'R') { x[i] = x[i - 1] + len; y[i] = y[i - 1]; }
		else if (wh == 'U') { x[i] = x[i - 1]; y[i] = y[i - 1] + len; }
		else { x[i] = x[i - 1]; y[i] = y[i - 1] - len; }
		Process1(min(x[i - 1], x[i]), min(y[i - 1], y[i]), max(x[i - 1], x[i]), max(y[i - 1], y[i]));
	}
	sort(hor.begin(), hor.end()); hor.erase(unique(hor.begin(), hor.end()), hor.end());
	sort(ver.begin(), ver.end()); ver.erase(unique(ver.begin(), ver.end()), ver.end());
	bl.assign(ver.size() + 1, vector <bool>(hor.size() + 1, false));
	dest.assign(ver.size() + 1, vector <bool>(hor.size() + 1, false));
	for (int i = 1; i <= n; i++)
		Process2(min(x[i - 1], x[i]), min(y[i - 1], y[i]), max(x[i - 1], x[i]), max(y[i - 1], y[i]));
	for (int i = 0; i <= ver.size(); i++) { Fill(i, 0); Fill(i, hor.size()); }
	for (int i = 0; i <= hor.size(); i++) { Fill(0, i); Fill(ver.size(), i); }
	for (int i = 1; i < ver.size(); i++)
		for (int j = 1; j < hor.size(); j++) if (!dest[i][j])
			res += ll(ver[i] - ver[i - 1]) * ll(hor[j] - hor[j - 1]);
	printf("%I64d\n", res);
	return 0;
}