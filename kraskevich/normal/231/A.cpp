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
 
typedef long long i64;


int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    vector<int> cnt(n, 0);
    int res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
        {
            int c;
            cin >> c;
            cnt[i] += c;
        }
    
    for (int i = 0; i < n; ++i)
        if (cnt[i] >= 2)
            ++res;
    
    cout << res;
    
    return 0;
}