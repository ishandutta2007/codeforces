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


int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++)
        cout << i << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << i << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << 2 * i % n << " ";
    return 0;
}