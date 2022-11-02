# include <iostream>
# include <cstdio>
using namespace std;

int dist(int i,int j) {
	return i != j;
}

int main() {
	int k, X, Y;
	scanf("%d", &k);
	scanf("%d:%d", &X,&Y);
	int x0 = X / 10, x1 = X % 10;
	int y0 = Y / 10, y1 = Y % 10;
	int cost = 100000, x, y;
	int l, r;
	if(k == 12) l = 1, r = 12;
	else l = 0, r = 23;
	for(int i = l; i <= r; ++i) {
		int k0 = i / 10, k1 = i % 10;
		int c = dist(k0, x0) + dist(k1, x1);
		for(int j = 0; j < 60; ++j) {
			int b0 = j / 10, b1 = j % 10;
			int d = dist(b0, y0) + dist(b1, y1);
			if(c + d < cost) {
				cost = c + d;
				x = i;
				y = j;
			}
		}
	}
	printf("%02d:%02d\n", x, y);
	return 0;
}