#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;


string a,b;
string d[7]={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int xa,xb;

int main() {
	cin>>a>>b;
	for (int i=0;i<7;i++) {
		if (a==d[i]) xa=i;
		if (b==d[i]) xb=i;
	}
	int delta=(xb+7-xa)%7;
	if (delta==0 || delta==2 || delta==3) puts("YES");
	else puts("NO");
	return 0;
}