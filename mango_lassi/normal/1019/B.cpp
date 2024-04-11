#include <iostream>
#include <random>
#include <time.h>
#include <stdlib.h>
using namespace std;

int n;
int h;

int ask(int i) {
	cout << "? " << (i%n+1) << endl;
	int v;
	cin >> v;
	return v;
}
int answer(int i = -1) {
	if (i >= 0) i = (i%n+1);
	cout << "! " << i << endl;
	exit(0);
}

void solve(int a, int b, int dir) {
	int m = (a + b) >> 1;
	int vm = ask(m);
	int vmh = ask(m + h);
	if (vm == vmh) answer(m);
	if (0 < (vm - vmh) * dir) solve(a, m, dir);
	else solve(m, b, dir);
}

int main() {
	// If f(a) = f(b + h) and f(b) = f(a + h),
	// Exists some 
	// If n % 4 == 2, solution can't exist
	srand(time(0));

	cin >> n;
	if (n % 4 == 2) answer();
	h = n / 2;

	int a = rand() % h;
	int b = a + h - 1;

	// Say va = vb + k
	// And that k > 1.

	int va = ask(a);
	int vb = ask(b);
	int vah = ask(a + h);
	int vbh = ask(b + h);
	if (va == vah) answer(a);
	if (vb == vbh) answer(b);
	// Now a...b is increasing and a+h...b+h is decreasing, and they intersect.
	// Or the other way around
	int dir = (va < vb ? 1 : -1);
	solve(a, b, dir);
}