#include <cstdio>
#include <list>

using namespace std;

int n;
char s[200005];
list<char> lst;

int main() {
	scanf("%d", &n);
	scanf(" %s", s);
	for (int i = 0; i < n; i++) {
		lst.push_back(s[i]);
	}
	char prev = '-';
	list <char> :: iterator it = lst.begin();
	while (it != lst.end()) {
		if (prev == '-') {prev = *it; ++it;}
		else if (*it == prev) lst.erase(it++);
		else {prev = '-'; ++it;}
	}
	if (lst.size() % 2 == 1) lst.pop_back();
	printf("%d\n", n - lst.size());
	for (list <char> :: iterator it = lst.begin(); it != lst.end(); ++it) {
		printf("%c", *it);
	}
	return 0;
}