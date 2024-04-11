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
    

    int n, k;
    cin >> n >> k;
    
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    sort(a, a + n);
    
    map<int, vector<int> > cur;
    vector<int> em(0);
    cur.insert(MP(0, em));
    
    for (int i = 0; i < n; ++i)
    {
        if (!cur.count(a[i]))
        {
            --k;
            cout << 1 << " " << a[i] << endl;
            vector<int> t;
            t.push_back(a[i]);
            cur.insert(MP(a[i], t));
        }
        
        if (!k)
            break;
            
        
        map<int, vector<int> > temp = cur;
        for (map<int, vector<int> >::iterator it = temp.begin(); it != temp.end(); ++it)
        {
            if (!k)
                break;
                
            int prev = it->F;
            vector<int> print = it->S;
            
            if (print.size() == 1 && print[0] == a[i])
                continue;
            
            if (cur.count(prev + a[i]) || temp.count(prev + a[i]))
                continue;
            
            --k;
            //cur.erase(prev);
            prev += a[i];
            print.push_back(a[i]);
            
            cout << print.size() << " ";
            for (int j = 0; j < print.size(); ++j)
                cout << print[j] << " ";
            cout << endl;
            
            cur.insert(MP(prev, print));
            
        }
        if (!k)
            break;
        
    } 
        
    
    //WAIT;
    
    return 0;
}