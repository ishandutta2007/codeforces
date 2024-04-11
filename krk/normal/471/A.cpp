#include <cstdio>
#include <map>
using namespace std;

map <int, int> freq;

int main()
{
	for (int i = 0; i < 6; i++) {
		int a; scanf("%d", &a);
		freq[a]++;
	}
	bool was = false;
	for (map <int, int>::iterator it = freq.begin(); it != freq.end(); it++)
		if (it->second >= 4) { it->second -= 4; was = true; break; }
	if (!was) { printf("Alien\n"); return 0; }
	int has[2], pnt = 0;
	for (map <int, int>::iterator it = freq.begin(); it != freq.end(); it++)
		while (it->second > 0) {
			has[pnt++]= it->first;
			it->second--;
		}
	if (has[0] != has[1])
		printf("Bear\n");
	else printf("Elephant\n");
	return 0;
}