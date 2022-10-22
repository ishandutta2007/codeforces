#include <cstdio>
#include <set>
using namespace std;

const int Maxn = 200005;

int n;
int a, b, c;
multiset <int> S;
int res;

int Remove(int x)
{
	multiset <int>::iterator it = S.upper_bound(x);
	if (it == S.begin()) return 0;
	it--; 
	int val = *it;
	S.erase(it);
	return val;
}

void Phase0()
{
	multiset <int>::iterator it;
	while (!S.empty()) {
		it = S.end(); it--;
		if (*it > b + c) {
			res++; S.erase(it);
		} else return;
	}
}

void Phase1()
{
	multiset <int>::iterator it;
	while (!S.empty()) {
		it = S.end(); it--;
		if (*it > a + c) {
			res++; S.erase(it); Remove(a);
		} else return;
	}
}

void Phase2()
{
	multiset <int>::iterator it;
	while (!S.empty()) {
		it = S.end(); it--;
		if (*it > max(a + b, c)) {
			res++; S.erase(it); Remove(b);
		} else return;
	}
}

void Phase3()
{
	multiset <int>::iterator it;
	while (!S.empty()) {
		it = S.end(); it--;
		if (*it > c) {
			res++; S.erase(it); Remove(c);
		} else break;
	}
	while (!S.empty()) {
		it = S.end(); it--;
		res++; S.erase(it);
		int v1 = Remove(a), v2 = Remove(b);
		if (!v1 || !v2) {
			if (v1) S.insert(v1);
			if (v2) S.insert(v2);
			Remove(a + b);
			break;
		}
	}
	while (!S.empty()) {
		it = S.end(); it--;
		res++; S.erase(it);
		Remove(a + b);
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%d %d %d", &a, &b, &c);
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	while (n--) {
		int t; scanf("%d", &t);
		S.insert(t);
	}
	if (*S.rbegin() > a + b + c) { printf("-1\n"); return 0; }
	Phase0();
	Phase1();
	Phase2();
	Phase3();
	printf("%d\n", res);
	return 0;
}