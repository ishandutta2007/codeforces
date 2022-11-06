#include <cstdio>
#include <algorithm>

const int N = 11;

int n;
char A[N][N], B[N][N];

inline void Flip_1() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n / 2; ++j) std::swap(A[i][j], A[i][n - j + 1]);
}
inline void Flip_2() {
	for (int i = 1; i <= n / 2; ++i)
		for (int j = 1; j <= n; ++j) std::swap(A[i][j], A[n - i + 1][j]);
}
inline int Check_1() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) if (A[i][j] != B[j][n - i + 1]) return 0;
	return 1;
}
inline int Check_2() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) if (A[i][j] != B[n - i + 1][n - j + 1]) return 0;
	return 1;
}
inline int Check_3() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) if (A[i][j] != B[n - j + 1][i]) return 0;
	return 1;
}
inline int Check_4() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) if (A[i][j] != B[i][j]) return 0;
	return 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%s", A[i] + 1);
	for (int i = 1; i <= n; ++i) scanf("%s", B[i] + 1);
	
	if (Check_1() || Check_2() || Check_3() || Check_4()) {
		puts("Yes");
		return 0;
	}
	
	Flip_1();
	if (Check_1() || Check_2() || Check_3() || Check_4()) {
		puts("Yes");
		return 0;
	}
	Flip_1();
	
	Flip_2();
	if (Check_1() || Check_2() || Check_3() || Check_4()) {
		puts("Yes");
		return 0;
	}
	Flip_2();
	
	puts("No");
	
	return 0;
}