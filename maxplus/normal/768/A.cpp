#include <iostream>
#include <set>

using namespace std;

multiset<int> a;

int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x, a.insert(x);
    a.erase(*a.begin());
    if (a.size())
        a.erase(*prev(a.end()));
    cout << a.size();
    return 0;
}