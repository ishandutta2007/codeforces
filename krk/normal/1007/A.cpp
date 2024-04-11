#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
deque <int> D;
int seq[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &seq[i]);
	sort(seq, seq + n);
	for (int i = 0; i < n; i++) {
		if (!D.empty() && D.front() < seq[i]) {
			res++; D.pop_front();
		}
		D.push_back(seq[i]);
	}
	printf("%d\n", res);
	return 0;
}