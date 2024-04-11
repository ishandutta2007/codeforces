#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 200005;

int m;
char tmp[15];
vector <iii> seq;
int res[Maxn];

bool Less(const iii &a, const iii &b)
{
	return a.first.first * b.first.second < a.first.second * b.first.first;
}

int main()
{
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", tmp);
		string s = tmp;
		int a = 0;
		int pnt = 1;
		while (s[pnt] != '+') {
			a = 10 * a + (s[pnt] - '0');
			pnt++;
		}
		pnt++;
		int b = 0;
		while (s[pnt] != ')') {
			b = 10 * b + (s[pnt] - '0');
			pnt++;
		}
		pnt++; pnt++;
		int c = 0;
		while (pnt < s.length()) {
			c = 10 * c + (s[pnt] - '0');
			pnt++;
		}
		seq.push_back(iii(ii(a + b, c), i));
	}
	sort(seq.begin(), seq.end(), Less);
	for (int i = 0, j; i < seq.size(); i = j) {
		j = i;
		while (j < seq.size() && !Less(seq[i], seq[j]))
			j++;
		for (int l = i; l < j; l++)
			res[seq[l].second] = j - i;
	}
	for (int i = 0; i < m; i++)
		printf("%d%c", res[i], i + 1 < m? ' ': '\n');
	return 0;
}