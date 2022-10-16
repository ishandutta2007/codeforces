#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main()
{
    int n, a[22];
    cin >> n;
    copy_n(istream_iterator<int>(cin), n, a);
    set<int> s(a, a + n);
    for (int i = 0; i < n; ++i)
        cout << *next(s.begin(), distance(s.begin(), s.upper_bound(a[i])) % n) << ' ';
    return 0;
}