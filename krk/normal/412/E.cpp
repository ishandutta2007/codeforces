#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

char s[Maxn];
int slen;
ll res;

int getNext(int cur)
{
	int ok = 0;
	while (cur < slen) {
		if (islower(s[cur])) ok++;
		else if (s[cur] == '@') break;
		else if (!isdigit(s[cur]) && s[cur] != '_') return cur + 1;
		cur++;
	}
	if (cur == slen) return cur + 1;
	int et = cur++;
	while (cur < slen) {
		if (s[cur] == '.') break;
		else if (!islower(s[cur]) && !isdigit(s[cur])) return et + 1;
		cur++;
	}
	if (cur == slen || et + 1 == cur) return cur + 1;
	int pnt = cur++;
	while (cur < slen && islower(s[cur])) cur++;
	res += ll(ok) * ll(cur - 1 - pnt);
	return pnt + 1;
}

int main()
{
	scanf("%s", s); slen = strlen(s);
	int cur = 0;
	while (cur < slen)
		cur = getNext(cur);
	printf("%I64d\n", res);
	return 0;
}