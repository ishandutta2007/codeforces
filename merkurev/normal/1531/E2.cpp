#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

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


const int N = (int) 1e5;
vector <int> g[N];

int ord_pos[N];
char str[N];
bool used[N];

vector <int> ord;

vector <int> a, b;


void merge_sort(int l, int r, int &shift)
{
    if (r - l <= 1)
        return;
    
    //eprintf("[%d, %d]\n", l, r);
    int m = (l + r) >> 1;

    merge_sort(l, m, shift);
    merge_sort(m, r, shift);
   
    int i = l;
    int j = m;
    int k = l;

    while (i < m && j < r)
    {
        if (str[shift] == '0')
        {
            //eprintf("0) %d -> %d\n", a[i], a[j]);
            g[a[i]].push_back(a[j]);
            b[k] = a[i];
            i += 1;
        }
        else if (str[shift] == '1')
        {
            //eprintf("1) %d -> %d\n", a[j], a[i]);
            g[a[j]].push_back(a[i]);
            b[k] = a[j];
            j += 1;
        }
        else
        {
            shift = -1;
            return;
        }
        shift++;
        k += 1;
    }
    while (i < m)
    {
        b[k] = a[i];
        i += 1;
        k += 1;
    }
    while (j < r)
    {
        b[k] = a[j];
        j += 1;
        k += 1;
    }
    for (int h = l; h < r; h++)
        a[h] = b[h];
}


void dfs_ord(int v)
{
    used[v] = true;
    for (int to : g[v])
        if (!used[to])
            dfs_ord(to);
    ord.push_back(v);
}

bool try_solve(int k)
{
    int len = strlen(str);

    for (int i = 0; i < k; i++)
        g[i].clear();

    a.clear();
    b.clear();
    for (int i = 0; i < k; i++)
    {
        b.push_back(0);
        a.push_back(i);
    }

    int shift = 0;
    merge_sort(0, k, shift);
    
    if (shift != len)
        return false;

    for (int i = 0; i < k; i++)
        used[i] = false;
    ord.clear();
    for (int i = 0; i < k; i++)
        if (!used[i])
            dfs_ord(i);
    reverse(ord.begin(), ord.end());
    for (int i = 0; i < k; i++)
        ord_pos[ord[i]] = i;

    for (int v = 0; v < k; v++)
        for (int to : g[v])
            if (ord_pos[v] >= ord_pos[to])
                return false;

    vector <int> ans(k);
    for (int i = 0; i < k; i++)
        ans[ord[i]] = i;

    printf("%d\n", k);
    for (int v : ans)
        printf("%d ", v + 1);
    printf("\n");

    return true;
}



int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%s", str);

    /*
    if (!try_solve(16))
        eprintf("FAIL\n");

    return 0;
    */

    for (int len = 1; ; len++)
    {
        eprintf("try len = %d\n", len);
        if (try_solve(len))
            break;
    }


	return 0;
}