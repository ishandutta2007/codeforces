# include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

vector<pii> A, B;

int main() {
	char buff[12];
	int n; scanf("%d", &n);
	int r = 1, c = 1;
	while(true) {
		printf("? %d %d %d %d\n", r, c, n, n);
		fflush(stdout);
		scanf("%s", buff);
		if(buff[0] == 'Y') {
			A.push_back(pii(r, c));
		} else {
			r += 1;
			c -= 1;
			A.push_back(pii(r, c));
		}
		if((n - r) + (n - c) == n - 1) break;
		c += 1;
	}
	r = n, c = n;
	while(true) {
		printf("? %d %d %d %d\n", 1, 1, r, c);
		fflush(stdout);
		scanf("%s", buff);
		if(buff[0] == 'Y') {
			B.push_back(pii(r, c));
		} else {
			r += 1;
			c -= 1;
			B.push_back(pii(r, c));
		}
		if((r - 1) + (c - 1) == n - 1) break;
		r -= 1;
	}
	assert(*A.rbegin() == *B.rbegin());
	reverse(B.begin(), B.end());
	putchar('!');
	putchar(' ');
	for(int i = 1; i < n; ++i) 
		putchar(A[i].first == A[i-1].first ? 'R' : 'D');
	for(int i = 1; i < n; ++i) 
		putchar(B[i].first == B[i-1].first ? 'R' : 'D');
	puts("");
	return 0;
}