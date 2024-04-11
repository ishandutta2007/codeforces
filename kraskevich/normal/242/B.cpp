#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    int left, rightleft, maxr, res;
    
    for (int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        
        if (!i || l < left)
            left = l, res = i + 1, rightleft = r;
        if (left == l && rightleft < r)
        {
            rightleft = r;
            res = i + 1;
        }
        if (!i)
            maxr = r;
        maxr = max(maxr, r);
    }
    
    if (maxr > rightleft)
        res = -1;
    
    cout << res;
    
    return 0;
}