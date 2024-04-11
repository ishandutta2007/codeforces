#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
char str[Maxn];
char A[Maxn], B[Maxn];

bool Ok(char S[])
{
	int st = 0;
	for (int i = 0; i < n; i++) {
		st += S[i] == '('? 1: -1;
		if (st < 0) return false;
	}
	return st == 0;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", str);
		int sam = 0, dif = 0;
		for (int i = 0; i < n; i++)
			if (str[i] == '1') sam++;
			else dif++;
		if (sam % 2 || dif % 2) printf("NO\n");
		else {
			sam /= 2;
			for (int i = 0; i < n; i++)
				if (str[i] == '1')
					if (sam > 0) { A[i] = B[i] = '('; sam--; }
					else A[i] = B[i] = ')';
				else if (dif % 2 == 0) { A[i] = '('; B[i] = ')'; dif--; }
					 else { A[i] = ')'; B[i] = '('; dif--; }
			A[n] = B[n] = '\0';
			if (!Ok(A) || !Ok(B)) printf("NO\n");
			else {
				printf("YES\n");
				printf("%s\n%s\n", A, B);
			}
		} 
	}
    return 0;
}