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
    
    int out = 0, in = 0, res = 0;
    
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '+')
        {
            if (out)
                --out;
            else
                ++res;
            ++in;
        }
        else
        {
            if (in)
                --in;
            else
                ++res;
            ++out;
        }
    }
    
    cout << res;
    
    
    return 0;
}