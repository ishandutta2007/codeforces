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

int main()
{
    ios_base::sync_with_stdio(0);
    
    ll n, m, h;
    
    cin >> h >> m >> n;
    
    vector<bool> u(h, false);
    
    ll bad = 0;
    map<int, int> was;
    for(int i = 0; i < n; ++i)
    {
            char c;
            
            cin >> c;
            
            if(c == '-')
            {
                 ll id;
                 cin >> id;
                 u[was[id]] = false;
                 was.erase(id); 
            }
            else
            {
                ll id, hash, j = 0;
                cin >> id >> hash;
                for(j = 0;; ++j)
                        if(!u[(hash + j * m) % h])
                        {
                                u[(hash + j * m) % h] = true;    
                                break;
                        }
                bad += j;
                was.insert(MP(id, (hash + j * m) % h));
            }
    }
    
    cout << bad;
    
    cin >> n;
    
    return 0;
}