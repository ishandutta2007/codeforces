#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <random>
#include <string>


#include <numeric>


#include <cmath>
#include <functional>
#include <limits>
#include <complex>


#include <queue>


#include <ostream>


 // namespace asl


 // namespace asl


 // namespace asl


 // namespace asl


 // namespace asl


 // namespace asl
 // namespace asl
 // namespace asl


#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> a, b;
    int u = 0, v = s.length() - 1;

    while (u < v)
    {
        while (u < v && s[u] == ')')
            ++u;
        while (u < v && s[v] == '(')
            --v;

        if (s[u] == '(' && s[v] == ')')
        {
            a.push_back(u);
            b.push_back(v);
            u++;
            v--;
        }
    }

    if (a.empty())
    {
        cout << 0 << endl;
        return 0;
    }

    cout << 1 << endl;

    cout << a.size() * 2 << endl;
    for (auto x : a)
        cout << x + 1 << " ";
    reverse(b.begin(), b.end());
    for (auto x : b)
        cout << x + 1 << " ";
    cout << endl;

    return 0;
}
// ()())
// ()