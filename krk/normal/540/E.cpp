#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn], b[Maxn];
vector <int> un;
vector <int> seq;
map <int, int> wh;
int BIT[Maxn];
ll res;

int isBetw(int a, int b) 
{
	if (a > b) return 0;
	return upper_bound(un.begin(), un.end(), b) - lower_bound(un.begin(), un.end(), a);
}

void Update(int x)
{
	for (int i = x; i > 0; i -= i & -i)
		BIT[i]++;
}

int Get(int x)
{
	int res = 0;
	for (int i = x; i < Maxn; i += i & -i)
		res += BIT[i];
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		un.push_back(a[i]); un.push_back(b[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	seq = un;
	for (int i = 0; i < un.size(); i++)
		wh[seq[i]] = i;
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
		b[i] = lower_bound(un.begin(), un.end(), b[i]) - un.begin();
		int pa = seq[a[i]], pb = seq[b[i]];
		swap(seq[a[i]], seq[b[i]]);
		wh[pa] = b[i]; wh[pb] = a[i];
	}
	for (map <int, int>::iterator it = wh.begin(); it != wh.end(); it++)
		if (un[it->second] < it->first) res += it->first - 1 - un[it->second] - isBetw(un[it->second] + 1, it->first - 1);
		else if (it->first < un[it->second]) res += un[it->second] - 1 - it->first - isBetw(it->first + 1, un[it->second] - 1);
	for (int i = 0; i < seq.size(); i++) {
		int ind = lower_bound(un.begin(), un.end(), seq[i]) - un.begin() + 1;
		res += Get(ind); Update(ind);
	}
	printf("%I64d\n", res);
	return 0;
}