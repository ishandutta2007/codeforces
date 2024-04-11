# include <iostream>
# include <cstdio>
using namespace std;

typedef long long ll;

int m;

int v1[1000010];
int v2[1000010];

void calc(ll &first,ll &circle,int e[]) {
	int h, a, x, y;
	scanf("%d%d%d%d", &h, &a, &x, &y);
	first = circle = -1;
	for(int k = 1; ;++k) {
		if(e[h] != 0) {
			circle = k - e[h];
			if(first == -1) {
				circle = -1;
			} else if(first + 1 < e[h]) {
				circle = 0;
			}
			return;
		}
		e[h] = k;
		if(h == a) {
			if(first == -1) first = k - 1;
		}
		h = (1ll * h * x + y) % m;
	}
}

ll exgcd(ll a,ll b,ll &x,ll &y) {
	if(b == 0) { x = 1, y = 0; return a;}
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x; return d;
}

ll gcd(ll a,ll b) {
	for(ll t;b;t=a,a=b,b=t%a);
	return a;
}

// Ax + C1 == By + C2
// x >= 0, y >= 0
// Ax + B(-y) == C2 - C1 == C

int main() {
	scanf("%d", &m);
	ll A, B, C1, C2, C, x, y;
	calc(C1, A, v1); 
	calc(C2, B, v2);
	//cout << A << ' ' << C1 << endl;
	//cout << B << ' ' << C2 << endl;
	if(A == 0 || B == 0) {
		if(A == 0 && B == 0) {
			cout << ((C1 == C2) ? C1 : -1) << endl;
		} else if (A == 0) {
			cout << ( ((C1 >= C2) && ((C1 - C2) % B == 0)) ? C1 : -1) << endl;
		} else {
			cout << ( ((C2 >= C1) && ((C2 - C1) % A == 0)) ? C2 : -1) << endl;
		}
		return 0;
	}
	if(C1 == -1 || C2 == -1) {
		cout << -1 << endl;
		return 0;
	}
	ll d = exgcd(A, B, x, y);
	C = C2 - C1;
	if(C % d) {
		cout << -1 << endl;
		return 0;
	} else {
		ll M = A / gcd(A, B) * B;
		x = x * (C / d) % M;
		y = y * (C / d) % M;
		ll t = ((A * x + C1) % M + M) % M;
		ll c = max(C1, C2);
		ll r = c / M * M + t;
		if(r >= c) {
			cout << r << endl;
		} else {
			cout << r + M << endl;
		}
	}
}