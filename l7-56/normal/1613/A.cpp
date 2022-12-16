#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
using namespace std;

int T,p1,p2;
db x1,x2;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lf%d%lf%d", &x1, &p1, &x2, &p2);
		while(x1 >= 10) x1 /= 10, p1++;
		while(x2 >= 10) x2 /= 10, p2++;
		if(p1 > p2 || (p1 == p2 && x1 > x2)) printf(">\n");
		else if(p1 == p2 && x1 == x2) printf("=\n");
		else printf("<\n");
	}
	return 0;
}