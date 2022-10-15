#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

long long n;

long long work() {
	if (n<=5) {
		if (n==1) return 1;
		else if (n==2) return 2;
		else if (n==3) return 6;
		else if (n==4) return 12;
		else return 60;
	}
	if (n&1) return n*(n-1)*(n-2);
	if (n%3==0) return (n-1)*(n-2)*(n-3);
	return n*(n-1)*(n-3);
}

int main() {
	cin>>n;
	cout<<work()<<endl;
	return 0;
}