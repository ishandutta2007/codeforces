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
#define m_p make_pair
#define p_b push_back

int main() 
{
    ios_base::sync_with_stdio(false);
    int n, b;
    cin >> n >> b;
    int a[n];
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    int all = 0;
    for(int i = 0; i < n; ++i)
            all += a[i];
    all += b;
    double mid = (double)all / n;
    for(int i = 0; i < n; ++i)
            if(a[i] * n > all)
             {
                    cout << -1;
                    return 0;
            }
    cout.setf(ios::fixed);
    cout.precision(10);
    for(int i = 0; i < n; ++i)
            cout << max(0.0, mid - a[i]) << endl;

    cin >> n;
    return 0;
}