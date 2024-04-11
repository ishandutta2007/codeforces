#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int P = 1000000007;
int f[100001], v[100001], test, m;

inline void add(int &x, int y){
	x += y;
	if (x >= P) x -= P;
}

int dec(int x, int y){
	int will = x - y;
	if (will < 0) will += P;
	return will;
}

int main(){
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	scanf("%d%d", &test, &m);
	memset(f, 0, sizeof(f));
	memset(v, 0, sizeof(v));
	f[0] = 1;
	for (int i = 0; i < 100000; i++)
	{
		add(f[i + 1], f[i]);
		if (i + m <= 100000) 
			add(f[i + m], f[i]);
	}
	for (int i = 1; i <= 100000; i++)
	{
		v[i] = f[i];
		add(v[i], v[i - 1]);
	}
	for (;test--;)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", dec(v[y], v[x - 1]));
	}
}