#include <cstdio>

inline int max(int a, int b){return a > b ? a : b;}
int main(){
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int s1 = max(a * 3 / 10, a - (a / 250 * c));
	int s2 = max(b * 3 / 10, b - (b / 250 * d));
	printf("%s\n", s1 == s2 ? "Tie" : (s1 < s2 ? "Vasya" : "Misha"));
	return 0;
}