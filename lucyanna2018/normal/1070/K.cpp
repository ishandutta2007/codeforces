#include<cstdio>

#define ran 101101

int n, m, s;
int a[ran];
int ans[ran], r;

int main() {
	scanf("%d%d", &n, &m);
	s=0;
	for(int i=0;i<n;i++) {
		scanf("%d", &a[i]);
		s+=a[i];
	}
	
	if (s%m!=0) {
		puts("No");
		return 0;
	}
	
	r=0;
	int t = 0;
	int piece = s/m;
	int nxt = piece;
	int last = -1;
	for(int i=0;i<n;i++) {
		t+=a[i];
		if (t>nxt) {
			puts("No");
			return 0;
		}
		if (t==nxt) {
			nxt+=piece;
			ans[r++] = i-last;
			last = i;
		}
	}
	
	puts("Yes");
	for(int i=0;i<r;i++) printf("%d%c", ans[i], i<r-1 ? ' ' : '\n');
	
	return 0;
}