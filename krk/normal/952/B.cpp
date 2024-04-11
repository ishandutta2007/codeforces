#include <bits/stdc++.h>
using namespace std;

multiset <string> normal;
multiset <string> grumpy;
const string sn[10] = {"no", "no", "no", "don't think so", "great!", "don't touch me!", "no", "no", "not bad", "cool"};
const string gn[10] = {"no", "no way", "no way", "don't even", "are you serious?", "go die in a hole", "worse", "no", "no", "terrible"};

int main()
{
	for (int i = 0; i < 10; i++) {
		normal.insert(sn[i]);
		grumpy.insert(gn[i]);
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", i); fflush(stdout);
		string s; getline(cin, s);
		multiset <string>::iterator it1 = normal.find(s);
		multiset <string>::iterator it2 = grumpy.find(s);
		if (it1 != normal.end() && it2 != grumpy.end()) {
			normal.erase(it1); grumpy.erase(it2);
		} else if (it1 != normal.end()) { printf("normal\n"); fflush(stdout); return 0; }
		else if (it2 != grumpy.end()) { printf("grumpy\n"); fflush(stdout); return 0; }
	}
	printf("normal\n");
	return 0;
}