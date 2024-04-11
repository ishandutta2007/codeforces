#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn], alen;
int b[Maxn], blen;
ll sum1, sum2;
bool lastfirst;

void First() { printf("first\n"); }

void Second() { printf("second\n"); }

int getStatus()
{
	for (int i = 0; i < alen && i < blen; i++)
		if (a[i] != b[i]) return a[i] > b[i]? 1: -1;
	if (alen != blen) return alen > blen? 1: -1;
	return 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num; scanf("%d", &num);
		if (num > 0) { a[alen++] = num; sum1 += num; lastfirst = true; }
		else { b[blen++] = -num; sum2 += -num; lastfirst = false; }
	}
	if (sum1 != sum2) 
		if (sum1 > sum2) First();
		else Second();
	else {
		int res = getStatus();
		if (res > 0) First();
		else if (res < 0) Second();
		else if (lastfirst) First();
		 	else Second();
	}
	return 0;
}