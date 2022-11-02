# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;

const int N = 100010;
char a[N]; int n, m;
int sx[N], sy[N], sz[N];
int main()
{
	scanf("%s", a); n = strlen(a);
	scanf("%d", &m);
	for(int i=0; i<n; i++) {
		switch(a[i]) {
			case 'x':sx[i+1]++; break;
			case 'y':sy[i+1]++; break;
			case 'z':sz[i+1]++; break;
		}
		sx[i+1] += sx[i];
		sy[i+1] += sy[i];
		sz[i+1] += sz[i];
	}
	int x, y, z, t, l, r;
	for(int k=0; k<m; k++) {
		scanf("%d%d", &l, &r);
		if(r - l < 2) {
			puts("YES"); continue;
		}
		x = sx[r] - sx[l-1];
		y = sy[r] - sy[l-1];
		z = sz[r] - sz[l-1];
		t = min(x,min(y,z));
		x -= t, y -= t, z -= t;
		if(x>1 || y>1 || z>1) {
			puts("NO"); continue;
		}
		puts("YES");
	}

	return 0;
}