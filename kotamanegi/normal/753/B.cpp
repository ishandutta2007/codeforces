#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream> 
#include<map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONG_INF 100000000000000
int not_used[10][10][10][10] = {};
pair<int,int> hit(int a, int b, int c, int d, int e, int f, int g, int h) {
	int burrow = 0,just = 0;
	if (a == e) just++;
	if (b == f) just++;
	if (c == g) just++;
	if (d == h) just++;
	vector<int> w, q;
	w.push_back(a);
	w.push_back(b);
	w.push_back(c);
	w.push_back(d);
	q.push_back(e);
	q.push_back(f);
	q.push_back(g);
	q.push_back(h);
	for (int i = 0;i < 4;++i) {
		for (int t = 0;t < 4;++t) {
			if (i != t) {
				if (w[i] == q[t]) burrow++;
			}
		}
	}
	return make_pair(just, burrow);
}
int input(int a, int b,int real,int c,int d,int e,int f) {
	int copy_used[10][10][10][10] = {};
	REP(i, 10) {
		REP(q, 10) {
			REP(j, 10) {
				REP(t, 10) {
					copy_used[i][q][j][t] = not_used[i][q][j][t];
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0;i < 10;++i) {
		for (int q = 0;q < 10;++q) {
			for (int j = 0;j < 10;++j) {
				for (int t = 0;t < 10;++t) {
					if (copy_used[i][q][j][t] == false) {
						pair<int, int> hoge = hit(i, q, j, t, c, d, e, f);
						if (hoge.first != a || hoge.second != b) {
							cnt++;
							copy_used[i][q][j][t] = true;
						}
					}
				}
			}
		}
	}
	if (real == true) {
		REP(i, 10) {
			REP(q, 10) {
				REP(j, 10) {
					REP(t, 10) {
						not_used[i][q][j][t] = copy_used[i][q][j][t];
					}
				}
			}
		}
	}
	return cnt;
}
int output(int a, int b, int c, int d) {
	cout << a << b << c << d << endl;
	fflush(stdout);
	int e, f;
	cin >> e >> f;
	input(e, f,1,a,b,c,d);
	if (e == 4) {
		return 1;
	}
	else return 0;
}
int cal_solve() {
	while (true) {
		int a, b, c, d;
		for (a = 0;a < 10;++a) {
			for (b = 0;b < 10;++b) {
				for (c = 0;c < 10;++c) {
					for (d = 0;d < 10;++d) {
						if (not_used[a][b][c][d] == false) {
							int poper = output(a, b, c, d);
							if (poper == 1) return 0;
							goto ok;
						}
					}
				}
			}
		}
	ok:;
	}
}
int main() {
	REP(i, 10) {
		REP(q, 10) {
			REP(j, 10) {
				REP(t, 10) {
					not_used[i][q][j][t] = true;
				}
			}
		}
	}
	REP(i, 10) {
		REP(q, 10) {
			if (i != q) {
				REP(j, 10) {
					if (j != i&&j != q) {
						REP(t, 10) {
							if (t != i&&t != q && t != j) {
								not_used[i][q][j][t] = false;
							}
						}
					}
				}
			}
		}
	}
	cal_solve();
	return 0;
}