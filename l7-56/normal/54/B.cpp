#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

const int maxn = 30, inf = 1e9;
struct Rec{
	int n,m,a[maxn][maxn];
	
	Rec(){
		n = m = 0;
		memset(a, 0, sizeof a);
	}
	
	friend bool operator == (Rec x, Rec y){
		if(x.n != y.n || x.m != y.m) return 0;
		for(int i = 1; i <= x.n; ++i)
			for(int j = 1; j <= x.m; ++j)
				if(x.a[i][j] != y.a[i][j]) return 0;
		return 1;
	}
	
	Rec subRec(int i, int j, int p, int q){
		Rec y;
		if(i + p - 1 > n || j + q - 1 > m) return y;
		y.n = p, y.m = q;
		for(int ii = 1; ii <= p; ++ii)
			for(int jj = 1; jj <= q; ++jj)
				y.a[ii][jj] = a[i + ii - 1][j + jj - 1];
		return y;
	}
	
	void print(){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j)
				printf("%d ", a[i][j]);
			putchar('\n');
		}
		return;
	}
}pic,puz[410];
int sp;

Rec turn_right(Rec x){
	Rec y;
	y.m = x.n, y.n = x.m;
	for(int i = 1; i <= x.n; ++i)
		for(int j = 1; j <= x.m; ++j)
			y.a[j][x.n - i + 1] = x.a[i][j];
	return y;
}

int main(){
	scanf("%d%d", &pic.n, &pic.m);
	for(int i = 1; i <= pic.n; ++i){
		string s;
		cin >> s;
		for(int j = 1; j <= pic.m; ++j)
			pic.a[i][j] = s[j - 1] - 'A';
	}
	
	int mx = inf,my = inf,ms = inf,cnt = 0;
	for(int x = pic.n; x >= 1; --x){
		if(pic.n % x) continue;
		for(int y = pic.m; y >= 1; --y){
			if(pic.m % y) continue;
			sp = 0;
			for(int p = 1; p <= pic.n; p += x)
				for(int q = 1; q <= pic.m; q += y)
					puz[++sp] = pic.subRec(p, q, x, y);
			//Sub
			bool flag = 1;
			for(int i = 1; i <= sp && flag; ++i)
				for(int j = i + 1; j <= sp && flag; ++j)
					if(puz[i] == puz[j] || puz[i] == turn_right(puz[j]) || puz[i] == turn_right(turn_right(puz[j])) || puz[i] == turn_right(turn_right(turn_right(puz[j]))))
						flag = 0;
//						printf("Erorr: %d %d %d %d\n", x, y, i, j);
			//Check
			if(flag){
				cnt++;
				if(ms > x * y || (ms == x * y && mx > x))
					ms = x * y, mx = x, my = y;
			}
//			printf("%d %d %d\n", x, y, flag);
//			for(int i = 1; i <= sp; ++i)
//				puz[i].print(), putchar('\n');
//			system("pause");
		}
	}
	printf("%d\n%d %d", cnt, mx, my);
	
	return 0;
}