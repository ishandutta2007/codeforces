#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int A, B, k;
int a[26];
char ss[202222];
bool d[202222];
#define i64 long long int
int main() {
	int _;
	for (scanf("%d", &_); _--;) {
		scanf("%d%d%d%s", &A, &B, &k, ss);
		memset(a, 0, sizeof(a));
		for (int i = 0;ss[i]; i++) a[ss[i] - 'A']++;
		i64 res = (i64)1e15;
		for (int X = 0; X < 26; X++) {
			memset(d, 0, sizeof(bool)*(k + 3));
			d[0] = 1;
			int s = 0;
			for (int i = 0; i < 26; i++)if(i!=X){
				for (int j = s; j >= 0; j--)if (d[j])d[j + a[i]] = true;
				s += a[i];
			}
			for (int M = 0; M <= s; M++) {
				if (!d[M])continue;
				if (M + a[X] < A || s - M + a[X] < B)continue;
				res = min(res, (i64)max(0, A - M) * max(0, B - (s - M)));
			}
		}
		cout << res << endl;
	}
	return 0;
}