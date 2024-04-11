#include <cstdio>
#include <string>
using namespace std;

int p, x;
string res, cand;

bool Get(int dig, string &cand)
{
	cand.resize(p);
	int lft = 0;
	for (int i = p - 1; i >= 0; i--) {
		int num = dig; cand[i] = num + '0';
		lft = x * num + lft;
		dig = lft % 10; lft /= 10;
	}
	return cand[0] != '0' && dig == cand[p - 1] - '0' && !lft;
}

void Update(string &res, const string &cand)
{
	if (res == "" || cand < res) res = cand;
}

int main()
{
	scanf("%d %d", &p, &x);
	for (int i = 1; i <= 9; i++)
		if (Get(i, cand)) Update(res, cand);
	if (res == "") printf("Impossible\n");
	else printf("%s\n", res.c_str());
	return 0;
}