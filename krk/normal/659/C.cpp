#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, m;
vector <int> has, res;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        has.push_back(a);
    }
    sort(has.begin(), has.end()); has.erase(unique(has.begin(), has.end()), has.end());
    int pnt = 0;
    for (int i = 1; i <= m; i++)
        if (pnt < has.size() && has[pnt] == i) pnt++;
        else { res.push_back(i); m -= i; }
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}