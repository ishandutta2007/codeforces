
#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int a[4], r[6];

int main() {
	printf("? 1 1\n");
	fflush(stdout);
	scanf("%d", &a[0]);
	if(a[0] == 0) exit(0);
	printf("? 2 3\n");
	fflush(stdout);
	scanf("%d", &a[1]);
	if(a[1] == 0) exit(0);
	printf("? 4 5\n");
	fflush(stdout);
	scanf("%d", &a[2]);
	if(a[2] == 0) exit(0);
	printf("? 2 4\n");
	fflush(stdout);
	scanf("%d", &a[3]);
	if(a[3] == 0) exit(0);

	r[0] = sqrt(a[0]);
	if(a[1] % 7 == 0) {
		r[1] = 42;
		r[2] = a[1] / 42;
	}else if(a[1] % 23 == 0) {
		r[1] = 23;
		r[2] = a[1] / 23;
	}else if(a[1] % 5 == 0) {
		r[1] = 15;
		r[2] = a[1] / 15;
	}else if(a[1] % 64 == 0) {
		r[1] = 16;
		r[2] = a[1] / 16;
	}else {
		r[1] = 4;
		r[2] = 8;
	}

	if(a[2] % 7 == 0) {
		r[3] = 42;
		r[4] = a[2] / 42;
	}else if(a[2] % 23 == 0) {
		r[3] = 23;
		r[4] = a[2] / 23;
	}else if(a[2] % 5 == 0) {
		r[3] = 15;
		r[4] = a[2] / 15;
	}else if(a[2] % 64 == 0) {
		r[3] = 16;
		r[4] = a[2] / 16;
	}else {
		r[3] = 4;
		r[4] = 8;
	}

	if(a[3] == r[1] * r[4]) {
		swap(r[3], r[4]);
	}else if(a[3] == r[2] * r[3]) {
		swap(r[1], r[2]);
	}else if(a[3] == r[2] * r[4]) {
		swap(r[3], r[4]);
		swap(r[1], r[2]);
	}

	set<int> s;
	s.insert(4);
	s.insert(8);
	s.insert(15);
	s.insert(16);
	s.insert(23);
	s.insert(42);
	printf("! ");
	for(int i = 0; i < 5; i++) {
		s.erase(r[i]);
		printf("%d ", r[i]);
	}
	printf("%d\n", *s.begin());
	fflush(stdout);
}