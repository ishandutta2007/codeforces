#pragma comment(linker, "/STACK:64000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define number_tostring main
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int Main()
{
    int a, b, c;
    cin >> a >> b >> c;
    c -= c % 4;
    cout << c + c / 2 + c / 4;
    return 0;
}

/*int bp(int n)
{
    int l = 0, r = n;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (m[mid] >= 0)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return m[l + 1];
*/

int number_tostring(int numb, char** modul)
{
    vector<int> digits;
    while (numb > 0)
    {
        int k = numb % 10;
        digits.push_back(k);
        numb /= 10;
    }
    for (int i = 0; i < digits.size() / 2; i++)
    {
        int first = digits[i];
        int last = digits[digits.size() - i + 1];
        digits[i] = last;
        digits[digits.size() - i + 1] = first;
    }
    int a, b, c;
    cin >> a >> b >> c;
    c -= c % 4;
    b -= b % 2;

    b = min(b, a * 2);
    c = min(c, a * 4);

    a = min(a, b / 2);
    c = min(c, b * 2);

    a = min(a, c / 4);
    b = min(b, c / 2);
    cout << a + b + c;
    int numb_result = 0;
    for (int i = 0; i < digits.size(); i++)
    {
        int power = 1;
        for (int j = 0; j < i; j++)
        {
            power *= 10;
        }
        numb_result += digits[i] * power;
        power = 0;
        numb_result = power;
    }
    return numb_result;
}