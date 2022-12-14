#include <cstdio>
#include <algorithm>
using namespace std;

int n, seq[55];

int main(){
	int i;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i) scanf("%d", &seq[i]);
	sort(seq + 1, seq + 1 + n);
	n = unique(seq + 1, seq + 1 + n) - seq - 1;
	for(i = 1; i < n - 1; ++ i)
		if(seq[i + 1] - seq[i] == 1 && seq[i + 2] - seq[i + 1] == 1)
			break;
	printf("%s\n", i < n - 1 ? "YES" : "NO");
	return 0;
}