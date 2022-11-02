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


const int N = 200 * 1000;
int a[N];
int b[N];
pair<int, int> s[N];
int ansA[N];
int ansB[N];
int n;

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i].first;
        s[i].second = i;
    }

    sort(s, s + n);

    int size = n / 3;
    if (n % 3 != 0)
        size++;
    for (int i = 0; i < size; i++)
    {
        a[i] = i;
        b[i] = s[i].first - i;
    }
    for (int i = size; i < 2 * size; i++)
    {
        a[i] = s[i].first - i;
        b[i] = i;
    }
    for (int i = 2 * size; i < n; i++)
    {
        int curr = n - i - 1;
        a[i] = s[i].first - curr;
        b[i] = curr;
    }
    for (int i = 0; i < n; ++i)
    {
        ansA[s[i].second] = a[i];
        ansB[s[i].second] = b[i];
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << ansA[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; ++i)
        cout << ansB[i] << " ";
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}