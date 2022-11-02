#include <algorithm>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define PII pair<int, int>
#define F first
#define S second


const int N = 50 * 1000 + 10;

char s[N];
int go[N];

int main()
{
    /*ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);*/

    gets(s);
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        go[i] = i + 1;
    int f = n;
    for (int len = 1; len <= n / 2; len++)
    {
        int l = 0;
        int t = 0;
        int k = 0;
        int r = 0;
        for (int i = 0; i < len; i++)
            r = go[r];
        for (; r < f;)
        {
            if (k == 0)
                t = l;
            if (s[l] == s[r])
                k++;
            else
                k = 0;
            if (k == len)
            {
                n -= len;
                go[l] = go[r];
                l = t;
                k = 0;
            }
            else
            {
                l = go[l];
            }
            r = go[r];
        }
    }
    for (int i = 0; i < f; i = go[i])
        putc(s[i], stdout);

    return 0;
}