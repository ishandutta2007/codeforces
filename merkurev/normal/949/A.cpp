#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = (int) 2e5 + 100;
char str[N];
vector <int> ans[N];
set <int> need[2];

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%s", str);
    int k = 0;
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        int c = str[i] - '0';
        if (need[c].empty() )
        {
            if (c == 1)
            {
                printf("-1\n");
                return 0;
            }
            else
                need[c].insert(k++);
        }
        int x = *need[c].begin();
        need[c].erase(x);
        need[c ^ 1].insert(x);
        ans[x].push_back(i);
    }
    if (!need[0].empty())
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d", (int) ans[i].size() );
        for (int x : ans[i] )
            printf(" %d", x + 1);
        printf("\n");
    }



	return 0;
}