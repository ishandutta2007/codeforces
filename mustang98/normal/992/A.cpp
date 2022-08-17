#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    set<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a) {
            s.insert(a);
        }
    }
    cout << s.size();

    return 0;
}