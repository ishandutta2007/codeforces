#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 1100005;
const int Maxd = 10;

char str[Maxn];
int slen;
int freq[Maxd];
char tmp[Maxn];
string subst;
string res;

bool Check(int x)
{
	int my[Maxd] = {};
	int num = x, digs = 0;
	while (num) {
		my[num % 10]++;
		digs++;
		num /= 10;
	}
	for (int i = 0; i < Maxd; i++)
		if (my[i] > freq[i]) return false;
	if (slen - digs != x) return false;
	if (x == subst.length())
		return subst[0] != '0' || x == 1;
	bool found = subst[0] != '0';
	for (int i = 1; i < Maxd && !found; i++)
		found = freq[i] > my[i]; 
	return found;
}

void Construct(int x)
{
	int num = x;
	while (num) {
		freq[num % 10]--;
		num /= 10;
	}
	if (x == subst.length()) { res = subst; return; }
	int i = 0;
	while (i + 1 < subst.length() && subst[i] == subst[i + 1]) i++;
	bool prior = i + 1 < subst.length() && subst[i] > subst[i + 1];
	int dig = 1;
	while (dig < Maxd && freq[dig] == 0) dig++;
	if (dig == Maxd) dig = 0;
	int sec = dig;
	for (int i = dig - 1; i >= 0; i--)
		if (freq[i] > 0) sec = i;
	string A(freq[0] + 1, '0'); A[0] = dig + '0';
	res.resize(x);
	int pnt = 0;
	bool used = false;
	if (dig != 0 && (subst[0] == '0' || dig < subst[0] - '0' || dig == subst[0] - '0' && !prior || 
						dig == subst[0] - '0' && A + subst < subst + A)) {
		res[pnt++] = dig + '0'; freq[dig]--;
	} else {
		for (int i = 0; i < subst.length(); i++)
			res[pnt++] = subst[i];
		used = true;
	}
	for (int dig = 0; dig < Maxd; dig++)
		while (freq[dig] > 0)
			if (used || dig < subst[0] - '0' || dig == subst[0] - '0' && !prior) {
				res[pnt++] = dig + '0'; freq[dig]--;
			} else {
				for (int i = 0; i < subst.length(); i++)
					res[pnt++] = subst[i];
				used = true;
			}
	if (!used)
		for (int i = 0; i < subst.length(); i++)
			res[pnt++] = subst[i];
}

int main()
{
	scanf("%s", str); slen = strlen(str);
	for (int i = 0; i < slen; i++)
		freq[str[i] - '0']++;
	scanf("%s", tmp); subst = tmp;
	for (int i = 0; i < subst.length(); i++)
		freq[subst[i] - '0']--;
	for (int i = subst.length(); i <= 1000000; i++)
		if (Check(i)) {
			Construct(i);
			printf("%s\n", res.c_str());
			return 0;
		}
	return 0;
}