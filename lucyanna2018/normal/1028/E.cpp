#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define ran 222222
#define i64 long long int
int n, a[ran], x;i64 c[ran];
int main() {
	scanf("%d", &n);
	x = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		x = max(x, a[i]);
	}
	if (x == 0) {
		puts("YES");
		for (int i = 0; i < n; i++)printf("1%c", i < n - 1 ? ' ' : '\n');
		return 0;
	}
	bool all = true;
	for (int i = 0; i < n; i++)if(a[i] != x){
		all = false;
		break;
	}
	if (all) {
		puts("NO");
		return 0;
	}
	puts("YES");
	int id = -1;
	for (int i = 0; i < n; i++)if (a[i] != 0 && a[i] != x) {
		id = i;
		break;
	}
	if (id != -1) {
		while (a[id] != x) {
			id++;
			if (id == n)id = 0;
		}
		i64 cur = 0;
		for (int i = 0; i < n; i++) {
			cur += a[id];
			c[id] = cur;
			id--;
			if (id == -1)id = n - 1;
		}
		for (int i = 0; i < n; i++)cout << c[i] << (i < n - 1 ? ' ' : '\n');
		return 0;
	}
	for (int i = 0; i < n; i++)if(a[i] == 0 && a[(i+1)%n]==x){
		id = i;
		break;
	}
	id = (id + 1) % n;
	i64 cur = 0;
	for (int i = 0; i < n; i++) {
		cur += a[id];
		if (i == 1)cur *= 2;
		c[id] = cur;
		id--;
		if (id == -1)id = n - 1;
	}
	for (int i = 0; i < n; i++)cout << c[i] << (i < n - 1 ? ' ' : '\n');
	return 0;
}