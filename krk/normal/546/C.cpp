#include <cstdio>
#include <deque>
using namespace std;

const int lim = 4000000;

int n;
deque <int> Q1, Q2;
int res;

int main()
{
	scanf("%d", &n);
	int n; 
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		Q1.push_back(a);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		Q2.push_back(a);
	}
	while (res <= lim && !Q1.empty() && !Q2.empty()) {
		res++;
		if (Q1.front() > Q2.front()) { Q1.push_back(Q2.front()); Q1.push_back(Q1.front()); }
		else { Q2.push_back(Q1.front()); Q2.push_back(Q2.front()); }
		Q1.pop_front(); Q2.pop_front();
	}
	if (res <= lim)
		printf("%d %d\n", res, Q1.empty()? 2: 1);
	else printf("-1\n");
	return 0;
}