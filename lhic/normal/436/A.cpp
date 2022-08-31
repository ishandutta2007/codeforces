#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <bitset>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>

typedef long long ll;
typedef long double ld;

using namespace std;

const int MAX_N = 100000;

int n, x;

struct cr
{
    int m;
    int h;
};

vector<cr> arr1;
vector<cr> arr2;
bool used1[3000];
bool used2[3000];


bool cmp(cr a,cr b)
{
    if (a.h < b.h)
        return true;
    else
        return false;
}

int solve(int a, int b, int x, int lst)
{
    while (a < arr1.size() && arr1[a].h <= x)
        ++a;
    while (b < arr2.size() && arr2[b].h <= x)
        ++b;
    if (lst == 1)
    {
        int ans=-1;
        int mx=0;
        for (int i = 0; i < a; ++i)
        {
            if (arr1[i].m > mx && !used1[i])
            {
                ans = i;
                mx = arr1[i].m;
            }
        }
        if (ans == -1)
            return 0;
        used1[ans] = true;
        return solve(a, b, x + arr1[ans].m, 1-lst) + 1;
    }
    else
    {
        int ans=-1;
        int mx=0;
        for (int i = 0; i < b; ++i)
        {
            if (arr2[i].m > mx && !used2[i])
            {
                ans = i;
                mx = arr2[i].m;
            }
        }
        if (ans == -1)
            return 0;
        used2[ans] = true;
        return solve(a, b, x + arr2[ans].m, 1-lst) + 1;
    }

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        cr a;
        cin >> a.h >> a.m;
        if (t == 0)
            arr1.push_back(a);
        else
            arr2.push_back(a);
    }
    sort(arr1.begin(), arr1.end(), cmp);
    sort(arr2.begin(), arr2.end(), cmp);
    int ans = solve(0, 0, x, 0);
    for (int i = 0; i < n; ++i)
    {
        used1[i] = false;
        used2[i] = false;
    }
    ans = max(ans, solve(0, 0, x, 1));
    cout << ans;
    return 0;
}