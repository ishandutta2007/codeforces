#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>


typedef long long LL;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int top = 0, bottom = 1, front = 2, back = 3, left = 4, right = 5;

std::string rotL(std::string s) {
	char c = s[left];
	s[left] = s[front];
	s[front] = s[right];
	s[right] = s[back];
	s[back] = c;
	return s;
}

std::string rotU(std::string s) {
	char c = s[top];
	s[top] = s[front];
	s[front] = s[bottom];
	s[bottom] = s[back];
	s[back] = c;
	return s;
}

std::string rotC(std::string s) {
	char c = s[top];
	s[top] = s[right];
	s[right] = s[bottom];
	s[bottom] = s[left];
	s[left] = c;
	return s;
}

std::set<std::string> got;

void ad(std::string s) {
	if (got.find(s) != got.end())
		return;
	got.insert(s);
	ad(rotL(s));
	ad(rotU(s));
	ad(rotC(s));
}

int main() {
	std::string s;
	std::cin >> s;
	std::sort(ALL(s));
	int result = 0;
	do {
		if (got.find(s) == got.end()) {
			++result;
			ad(s);
		}
	} while (std::next_permutation(ALL(s)));
	std::cout << result << std::endl;
}