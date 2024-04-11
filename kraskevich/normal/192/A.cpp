#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <list>
#include <stdlib.h>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;

typedef long long i64;
#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>
#define forn for(int i = 0; i < n; ++i)

int main()
{
    ios_base::sync_with_stdio(0);
    
    i64 n;
    cin >> n;
   
    vector<i64> t;
    set<i64> u;
    for(i64 i = 1;;++i)
    {
           i64 cur = i * (i + 1) / 2;
           if(cur > n)
                  break;
           u.insert(cur);
           t.push_back(cur);
    } 
    
    for(int i = 0; i < t.size(); ++i)
            if(u.count(n - t[i]))
            {
                         cout << "YES";
                         cin >> n;
                         return 0;
            }
    
    cout << "NO";
    cin >> n;
    return 0;
}