#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

int a[6];

void input()
{
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
}

#define SQ(x) ((x) * (x))

void run()
{
//    int b[6];
//    for (int i = 0; i < 6; i++) {
//		b[i] = a[i];
//    }
    // extend corners
//    while (b[1]) { b[1]--; b[0]++; b[2]++; }
//    while (b[3]) { b[3]--; b[2]++; b[4]++; }
//    while (b[5]) { b[5]--; b[4]++; b[0]++; }
//
//    for (int i = 0; i < 6; i++) {
//		cerr << b[i] << " ";
//    }
//    cerr << endl;
	cout << (SQ(a[2] + a[1] + a[3]) - SQ(a[1]) - SQ(a[3]) - SQ(a[5])) << endl;
}

int main()
{
#ifdef LOCAL
	assert(freopen("input.txt", "r", stdin));
	while (input(), cin) {
		run();
	}
#else
	input();
	run();
#endif // LOCAL
    return 0;
}