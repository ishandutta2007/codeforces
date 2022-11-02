#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
 
using namespace std;
 
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define F first
#define S second
#define WAIT int w; cin >> w;
#define ALL(x) x.begin(), x.end()






 
int main()
{
    ios_base::sync_with_stdio(0);
    
    string s;
    cin >> s;
    
    int cur = 0;
    int start;
    
    if (s.substr(0, 3) == "ftp")
    {
        start = 3;
        cout << "ftp://";
    }
    else
    {
        start = 4;
        cout << "http://";
    }
    
    cur = s.length() - 2;
    for (;; cur--)
        if (s.substr(cur, 2) == "ru")
            break;
    
    for (int i = start; i < cur; ++i)
        cout << s[i];
    cout << ".";
    
    cout << "ru";
    
    cur += 2;
    if (cur != s.length()) 
        cout << "/" + s.substr(cur, s.length() - cur);
    
    
    //WAIT;
            
    
    return 0;
}