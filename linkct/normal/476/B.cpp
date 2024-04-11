#include <cstdio>
#include <cstring>
#include <algorithm>
using std :: sort;

inline int getPri(const char x){
	switch(x){
		case '+': return 1;
		case '-': return 0;
		case '?': return 2;
	}
	return -1;
}
bool cmp(const char a, const char b){
	return getPri(a) < getPri(b);
}
inline int abs(int x){return x >= 0 ? x : -x;}
char str1[15], str2[15];

inline int f(int x){
	int ret = 1, i;
	for(i = 2; i <= x; ++ i) ret *= i;
	return ret;
}
inline int c(int n, int m){
	if(n < m || m < 0) return 0;
	return f(n) / f(m) / f(n - m);
}
int main(){
	int len, i, cnt = 0;
	scanf("%s%s", str1, str2);
	len = strlen(str1);
	for(i = 0; i < len; ++ i)
		cnt += getPri(str1[i]);
	sort(str2, str2 + len, cmp);
	for(i = 0; i < len && getPri(str2[i]) < 2; ++ i)
		cnt -= getPri(str2[i]);
	printf("%.15f\n", (double)c(len - i, cnt) / (1 << (len - i)));
	return 0;
}