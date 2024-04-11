#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>

vector<int> a, b, c;

void print(vector<int> v)
{
    cout << v.size() << " ";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;

        if (x < 0)
            a.push_back(x);
        if (x > 0)
            b.push_back(x);
        if (x == 0)
            c.push_back(x);
    }
    if (b.size() == 0)
        for (int i = 0; i < 2; ++i)
        {
            b.push_back(a.back());
            a.pop_back();
        }
    if (a.size() % 2 == 0)
    {
        c.push_back(a.back());
        a.pop_back();
    }
    print(a);
    print(b);
    print(c);
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}