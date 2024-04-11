#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef pair <int, string> is;

const int Maxl = 50;
const int Maxm = 10005;

char tmp[Maxl];
int n, m;
vector <is> has[Maxm];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int reg, p;
        scanf("%s %d %d", tmp, &reg, &p);
        has[reg].push_back(is(p, tmp));
    }
    for (int i = 1; i <= m; i++) {
        sort(has[i].begin(), has[i].end());
        if (has[i].size() > 2 && has[i][has[i].size() - 3].first == has[i][has[i].size() - 2].first)
            printf("?\n");
        else printf("%s %s\n", has[i][has[i].size() - 2].second.c_str(), has[i].back().second.c_str());
    }
	return 0;
}