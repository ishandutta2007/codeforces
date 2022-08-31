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


const int N = 2005;
char s[N], t[N];
map <char, int> M;

vector <int> ans;
int n;

void op(int pos)
{
    ans.push_back(pos);
    rotate(s, s + pos, s + n);
    reverse(s, s + n - pos);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &n);
    scanf("%s%s", s, t);

    for (int i = 0; i < n; i++)
    {
        M[s[i] ]++;
        M[t[i] ]--;
    }
    for (auto p : M)
        if (p.second != 0)
        {
            printf("-1\n");
            return 0;
        }

    int tl = (n + 1) / 2, tr = (n + 1) / 2;

    for (int it = 0; it < n; it++)
    {
        int len = it;
       
        char c;
        if (it % 2 == 0)
            c = t[--tl];
        else
            c = t[tr++];
        
        int pos = -1;
        for (int i = len; i < n; i++)
            if (s[i] == c)
                pos = i;
        
        op(pos + 1);
        op(n - pos - 1 + len);
        op(n - len);
    }
    if (n % 2 == 1)
        op(0);
//    eprintf("\ns = %s\nt = %s\n", s, t);


    printf("%d\n", (int) ans.size() );
    for (int x : ans)
        printf("%d ", n - x);
    printf("\n");

	return 0;
}