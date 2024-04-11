#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
using namespace std;

#define ll long long
#define sqr(a) (a) * (a)
#define S second
#define F first
#define MP make_pair
#define PB push_back

int per(string s)
{
    int n = s.length();
    vector<int> p(n, 0);
    for(int i = 1, k = 0; i < n; ++i)
    {
            while(s[i] != s[k] && k)
                       k = p[k - 1];
            if(s[i] == s[k])
                    ++k;
            p[i] = k;
    }
    return n % (n - p[n - 1]) == 0 ? n - p[n - 1] : n;
}

bool eq(string a, string b, int l)
{
     for(int i = 0; i < l; ++i)
             if(a[i]!= b[i])
                       return false;
     return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    string a, b;
    
    cin >> a >> b;
    
    int pa = per(a), pb = per(b);
    
    if(pa == 0 || pb == 0 || pa != pb || !eq(a, b, pa))
    {
          cout << 0;
          return 0;
    }
    
    int ans = 0;
    for(int i = 1; i <= min(a.length(), b.length()); ++i)
            if(i % pa == 0 && a.length() % i == 0 && b.length() % i == 0)
                 ans++;
    
    cout << ans;
    
    cin >> pa;
     
    return 0;
}