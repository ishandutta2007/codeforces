#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int T;
int n;
char str[Maxn];
vector <int> seq;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", str);
		seq.clear();
		for (int i = 0; i < n; i++)
			if (str[i] == '*')
				seq.push_back(i);
		int ind = seq.size() / 2;
		long long res = 0;
		for (int i = 0; i < seq.size(); i++)
			if (i < ind) res += abs(seq[i] - (seq[ind] - (ind - i)));
			else if (ind < i) res += abs(seq[i] - (seq[ind] + (i - ind)));
		printf("%I64d\n", res);
	}
    return 0;
}