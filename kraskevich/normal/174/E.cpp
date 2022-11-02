#include <iostream>
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
#define m_p make_pair
#define p_b push_back

int main() 
{
    ios_base::sync_with_stdio(false);
    int la, lb;
    cin >> la >> lb;
    int a[la * 2], b[lb];
    vector<int> pos(1000 * 1000 + 1, -1);
    for(int i = 0; i < la; ++i) {
            cin >> a[i];
            a[la + i] = a[i];
    }
    for(int i = 0; i < lb; ++i) {
            cin >> b[i];
            pos[b[i]] = i;
    }
    int res = 0, prev = -1, cur = 0;
    for(int i = 0; i < la * 2; ++i) {
            if(i > cur) 
                 prev = -1, cur = i;
            int start = pos[a[i]];
            for(;;++cur) {
                         if(cur >= la * 2)
                                break;
                         if(pos[a[cur]] == -1)
                                        break;
                         if(pos[a[cur]] > start)
                                if(prev != -1 && prev < start || prev > pos[a[cur]])
                                        break;
                         if(pos[a[cur]] < start)
                                        if(prev != -1 && prev < start && prev > pos[a[cur]])
                                                break;
                         prev = pos[a[cur]];
            }
            res = max(res, cur - i);
    }
                           
    
    cout << min(res, min(la, lb));
    
    cin >> la;
    
    return 0;
}