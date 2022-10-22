#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

string s, t;
int h1, m1, h2, m2;

int main(void)
{
	cin >> s >> t;
	h1 = atoi(s.substr(0, 2).c_str());
	m1 = atoi(s.substr(3, 2).c_str());
	h2 = atoi(t.substr(0, 2).c_str());
	m2 = atoi(t.substr(3, 2).c_str());
	
	int x = h1*60+m1, y = h2*60+m2;
	int ans = (x+y)/2;
	printf("%02d:%02d\n", ans/60, ans%60);
	return 0;
}