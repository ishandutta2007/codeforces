#include <stdio.h>

const long long mod = 1000000007;
const int Z = 1 << 17;

struct node{
	node(){
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) a[i][j] = 0;
		a[0][0] = a[1][1] = 1;
	}
	node(int p, int q, int r, int s)
	{
		a[0][0] = p;
		a[0][1] = q;
		a[1][0] = r;
		a[1][1] = s;
	}
	long long a[2][2];

	node operator *(node t){
		node r(0, 0, 0, 0);
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++){
			r.a[i][j] = (r.a[i][j] + a[i][k] * t.a[k][j]) % mod;
		}
		return r;
	}

	node operator +(node t){
		node r(0, 0, 0, 0);
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++){
			r.a[i][j] = (a[i][j] + t.a[i][j]) % mod;
		}
		return r;
	}

	node operator ^(int t){
		node r, v = (*this);
		while (t){
			if (t & 1) r = r * v;
			v = v * v;
			t /= 2;
		}
		return r;
	}
};

struct rnode{
	rnode(){
		a = node();
		b = node();
	}
	rnode(node A){
		a = b = A;
	}
	rnode(node A, node B){
		a = A;
		b = B;
	}
	node a, b;
	rnode operator *(rnode t){
		return rnode(a * t.a, b + a * t.b);
	}
}it[Z * 2];

int N, M;

void in(int p, node t)
{
	p += Z;
	it[p] = rnode(it[p].a * t);
	p /= 2;
	while (p){
		it[p] = it[p * 2] * it[p * 2 + 1];
		p /= 2;
	}
}

rnode out(int x, int y)
{
	rnode u, v;
	x += Z; y += Z;
	while (x < y){
		if (x & 1){
			u = u * it[x];
			x++;
		}
		if (~y & 1){
			v = it[y] * v;
			y--;
		}
		x /= 2;
		y /= 2;
	}
	if (x == y){
		u = u * it[x];
	}
	return u * v;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int p = Z - 1; p >= 1; p--) it[p] = it[p * 2] * it[p * 2 + 1];
	for (int i = 1; i <= N; i++){
		int x; scanf("%d", &x);
		in(i, node(1, 1, 1, 0) ^ x);
		in(i+1, node(0, 1, 1, -1) ^ x);
	}

	while (M--){
		int o; scanf("%d", &o);
		if (o == 1){
			int l, r, x; scanf("%d %d %d", &l, &r, &x);
			in(l, node(1, 1, 1, 0) ^ x);
			in(r + 1, node(0, 1, 1, -1) ^ x);
		}
		else{
			int l, r; scanf("%d %d", &l, &r);
			rnode u = out(l, r), v = out(0,l-1);
			u.a = u.a * v.a;
			u.b = u.b * v.a;
			printf("%lld\n", ((u.b.a[0][1]-u.a.a[0][1]-v.a.a[0][1]+2*mod) % mod + mod) % mod);
		}
	}

	return 0;
}