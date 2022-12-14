#include <cstdio>
#include <cstring>
const int MAXL = 405;

int k;
char str[MAXL];

inline int max(int a, int b){return a > b ? a : b;}
bool check(int s, int t){
	int mid = (s + t) >> 1;
	for(t = s; s <= mid; ++ s)
		if(str[s] != str[s + mid - t + 1] && str[s] != '?' && str[s + mid - t + 1] != '?')
			return false;
	return true;
}
int main(){
	int i, j, len, ans = 0;
	scanf("%s%d", str + 1, &k);
	len = strlen(str + 1);
	for(i = len + 1; i <= len + k; ++ i)
		str[i] = '?';
	len += k;
	for(i = 1; i <= len; ++ i)
		for(j = i + 1; j <= len; ++ j)
			if((j - i) % 2 && check(i, j))
				ans = max(ans, j - i + 1);
	printf("%d\n", ans);
	return 0;
}