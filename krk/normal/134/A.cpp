#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn], sum;
vector <int> res;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++)
        if (sum - a[i] == (n - 1) * a[i]) res.push_back(i);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i + 1 < res.size()) cout << " ";
        else cout << endl;
    }
    return 0;
}