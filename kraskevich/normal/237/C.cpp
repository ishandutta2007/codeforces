#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cassert>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>
#define REP(i, l, r) for (int i = l; i < r; ++i)
#define REPDOWN(i, r, l) for (int i = r; i >= l; --i)
#define FORN for (int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define PB push_back
 
typedef long long i64;

const int N = 1000 * 1000 + 1;
bool prime[N];
int a, b, k;

void calc()
{
    for (int i = 0; i < N; ++i)
        prime[i] = 1;
    prime[0] = prime[1] = 0;
    for (long long i = 2; i < N; ++i)
        if (prime[i])
            for (long long j = i * i; j < N; j += i)
                prime[j] = false;
}

bool can(int len)
{
    int cur = 0;
    for (int i = a; i <= a + len - 1; ++i)
        if (prime[i])
            ++cur;
    
    if (cur < k)
        return false;
    
    for (int l = a, r = a + len; r <= b; ++l, ++r)
    {
        if (prime[l])
            --cur;
        if (prime[r])
            ++cur;
        if (cur < k)
            return false;
    }
    
    return true;
}
    


int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> a >> b >> k;
    
    calc();
    
    int l = 1, r = b - a + 1;
    while(l < r)
    {
        int m = (l + r) / 2;
        if (can(m))
            r = m;
        else
            l = m + 1;
    }
    
    if (!can(l))
        l = -1;
    
    cout << l;
   
    return 0;
}