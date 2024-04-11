#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];

int gcd(int x, int y) { return x? gcd(y % x, x): y; } 

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		list <deque <int> > seq;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			deque <int> tmp; tmp.push_back(i);
			seq.push_back(tmp);
		}
		vector <int> res;
		auto it = seq.begin();
		while (true) {
			auto it2 = it; it2++;
			if (it2 == seq.end()) it2 = seq.begin();
			if (gcd(a[(*it).back()], a[(*it2).front()]) != 1)
				if (seq.size() == 1) break;
				else if ((*it).size() >= (*it2).size()) {
					for (int i = 0; i < (*it2).size(); i++)
						(*it).push_back((*it2)[i]);
					seq.erase(it2);
				} else {
					for (int i = (*it).size() - 1; i >= 0; i--)
						(*it2).push_front((*it)[i]);
					seq.erase(it);
					it = it2;
				}
			else {
				res.push_back((*it2).front());
				(*it2).pop_front();
				if ((*it2).empty()) seq.erase(it2);
				if (seq.size() == 0) break;
				it++;
			}
			if (it == seq.end()) it = seq.begin();
		}
		printf("%d", int(res.size()));
		for (int i = 0; i < res.size(); i++)
			printf(" %d", res[i]);
		printf("\n");
	}
    return 0;
}