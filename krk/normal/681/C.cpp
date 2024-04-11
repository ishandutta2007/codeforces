#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

priority_queue <int> Q;
int n;
char str[50];
vector <string> res;

string toString(int x)
{
	stringstream ss; ss << x;
	string s; ss >> s;
	return s;
}

int main()
{
	scanf("%d", &n);
	while (n--) {
		scanf("%s", str);
		int val; scanf("%d", &val);
		if (str[0] == 'i') { Q.push(-val); res.push_back("insert " + toString(val)); }
		else if (str[0] == 'g') {
			while (!Q.empty() && -Q.top() < val) {
				Q.pop(); res.push_back("removeMin");
			}
			if (Q.empty() || -Q.top() > val) {
				Q.push(-val); res.push_back("insert " + toString(val));
			}
			res.push_back("getMin " + toString(val));
		} else {
			if (Q.empty()) { Q.push(0); res.push_back("insert 0"); }
			Q.pop(); res.push_back("removeMin");
		}
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%s\n", res[i].c_str());
	return 0;
}