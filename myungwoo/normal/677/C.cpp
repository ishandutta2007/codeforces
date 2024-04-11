#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
typedef long long lld;

const int MOD = 1e9 + 7;
char S[MAXN];

inline int tonum(char c){
	if (isdigit(c)) return c-'0';
	if (isupper(c)) return c-'A'+10;
	if (islower(c)) return c-'a'+36;
	if (c == '-') return 62;
	return 63;
}

int main()
{
	int zero = 0, one = 0;
	scanf("%s", S);
	for (int i=0;S[i];i++){
		int v = tonum(S[i]);
		for (int j=0;j<6;j++){
			if (v&1) one++;
			else zero++;
			v >>= 1;
		}
	}
	int ans = 1;
	for (int i=0;i<zero;i++){
		ans = (lld)ans*3%MOD;
	}
	printf("%d\n", ans);
}