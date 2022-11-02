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
    
    int alla = 0, allb = 0, gooda = 0, goodb = 0;
    
    for (int i = 0; i < n; ++i)
    {
        int t, x, y;
        cin >> t >> x >> y;
        
        if (t == 1)
        {
            alla += (x + y);
            gooda += x;
        }
        else
        {
            allb += (x + y);
            goodb += x;
        }
    }
    
    if (gooda * 2 >= alla)
        cout << "LIVE";
    else
        cout << "DEAD";
    cout << endl;
    
    if (goodb * 2 >= allb)
        cout << "LIVE";
    else
        cout << "DEAD";
    cout << endl;
    
    //WAIT;
            
    
    return 0;
}