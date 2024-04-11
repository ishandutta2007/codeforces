#include<cstdio>
int main(void){
	int a[10000];
	int m[10001];
	int n;
	int t;
	int x;
	int l, r, b;
	int c;
	scanf("%d %d", &n,&t);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		m[a[i]] = i;
	}
	for (int tt = 0; tt < t; tt++){
		scanf("%d %d %d", &l, &r, &b);
		l--;
		b--;
		c = 0;
		for (int i = l; i < r; i++){
			if (a[b] > a[i])c++;
		}
		if (m[a[b]] == c + l)printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}