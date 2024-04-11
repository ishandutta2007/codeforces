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


const int LEN = 11;
char str[LEN];

vector <string> v[LEN];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    int sumLen = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        int len = strlen(str);
        string s = string(str);
        v[len].push_back(s);
        sumLen += len;
    }
    int oneLen = sumLen / (n / 2);

    for (int i = 1; i < LEN; i++)
    {
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
    }
    
    scanf("%s", str);
    char ch = str[0];


    for (int it = 0; it < n / 2; it++)
    {
        string bst = "";
        int aLen = 0, bLen = 0;

        for (int i = 1; i < oneLen; i++)
        {
            int j = oneLen - i;
            if (j == i)
            {
                if (v[i].size() >= 2)
                {
                    string cur = v[i].back();
                    cur.push_back(ch);
                    cur += v[i][(int) v[i].size() - 2];
                
                    if (bst == "" || cur < bst)
                    {
                        bst = cur;
                        aLen = i;
                        bLen = j;
                    }
                }
            }
            else
            {
                if (!v[i].empty() && !v[j].empty())
                {
                    string cur = v[i].back();
                    cur.push_back(ch);
                    cur += v[j].back();

                    if (bst == "" || cur < bst)
                    {
                        bst = cur;
                        aLen = i;
                        bLen = j;
                    }
                }
            }
        }

        v[aLen].pop_back();
        v[bLen].pop_back();
        printf("%s\n", bst.c_str());
    }



	return 0;
}