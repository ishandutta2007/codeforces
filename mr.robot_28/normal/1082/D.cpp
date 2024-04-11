#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 1000 + 7;

int n;
int a[N];

int main() {
	scanf("%d", &n);
	forn(i, n)
		scanf("%d", &a[i]);
	
	int sum = 0;
	forn(i, n)
		sum += a[i];
	
	if (sum < 2 * n - 2){
		puts("NO");
		return 0;
	}
	
	vector<int> ones;
	forn(i, n) if (a[i] == 1){
		a[i] = 0;
		ones.push_back(i);
	}
	
	int t = ones.size();
	int dm = (n - t) - 1 + min(2, t);
	printf("YES %d\n%d\n", dm, n - 1);
	
	int lst = -1;
	if (!ones.empty()){
		lst = ones.back();
		ones.pop_back();
	}
	
	forn(i, n){
		if (a[i] > 1){
			if (lst != -1){
				--a[lst];
				--a[i];
				printf("%d %d\n", lst + 1, i + 1);
			}
			lst = i;
		}
	}
	
	for (int i = n - 1; i >= 0; --i){
		while (!ones.empty() && a[i] > 0){
			--a[i];
			printf("%d %d\n", i + 1, ones.back() + 1);
			ones.pop_back();
		}
	}
	return 0;
}