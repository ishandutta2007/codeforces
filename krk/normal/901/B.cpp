#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

int n;
deque <int> D1, D2;

int main()
{
	scanf("%d", &n);
	D1.push_back(0); D2.push_back(1);
	for (int i = 0; i < n; i++) {
		deque <int> D3 = D1;
		D1 = D2; D2.push_front(0);
		for (int i = 0; i < D2.size(); i++) {
			int val = D2[i];
			if (i < D3.size()) val += D3[i];
			D2[i] = val % 2;
		}
	}
	printf("%d\n", int(D2.size()) - 1);
	for (int i = 0; i < D2.size(); i++)
		printf("%d%c", D2[i], i + 1 < D2.size()? ' ': '\n');
	printf("%d\n", int(D1.size()) - 1);
	for (int i = 0; i < D1.size(); i++)
		printf("%d%c", D1[i], i + 1 < D1.size()? ' ': '\n');
	return 0;
}