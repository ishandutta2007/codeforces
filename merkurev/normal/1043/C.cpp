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


const int N = 1005;
char str[N];
int ans[N];

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%s", str);
    int n = strlen(str);
    
    int rev = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == 'a')
        {
            ans[i] = (1 ^ rev);
        }
        else
        {
            ans[i] = rev;
        }
        rev ^= ans[i];
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");


	return 0;
}