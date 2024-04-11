#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

int overtakes;
vector <int> speeds;
int myspeed;
int n;
int res;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int s; scanf("%d", &s);
			while (!speeds.empty() && speeds.back() < s) {
				speeds.pop_back(); res++;
			}
			myspeed = s;
		} else if (t == 2) { res += overtakes; overtakes = 0; }
		else if (t == 3) {
			int s; scanf("%d", &s);
			if (myspeed > s) res++;
			else speeds.push_back(s);
		} else if (t == 4) {
			overtakes = 0;
		} else if (t == 5) {
			speeds.clear();
		} else if (t == 6) {
			overtakes++;
		}
	}
	printf("%d\n", res);
	return 0;
}