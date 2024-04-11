#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

typedef long long ll;

const int Maxl = 26;
const int Maxn = 100005;

int val[Maxl];
char str[Maxn];
int slen;
map <ll, int> F[Maxl];
ll res;

int main()
{
	for (int i = 0; i < Maxl; i++)
		scanf("%d", &val[i]);
	scanf("%s", str); slen = strlen(str);
	ll cur = 0;
	for (int i = 0; i < slen; i++) {
		if (F[str[i] - 'a'].find(cur) != F[str[i] - 'a'].end())
			res += F[str[i] - 'a'][cur];
		cur += val[str[i] - 'a'];
		F[str[i] - 'a'][cur]++;
	}
	printf("%I64d\n", res);
	return 0;
}