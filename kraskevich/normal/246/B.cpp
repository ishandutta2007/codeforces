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
    
    int n;
    cin >> n;
    
    long long a, sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        sum += a;
    }
    
    cout << (sum % n ? n - 1 : n);
    
    return 0;
}