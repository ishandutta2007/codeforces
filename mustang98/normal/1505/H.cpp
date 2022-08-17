#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 12, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    vector<int> a = {44, 12, 49, 17, 10, 25, 18, 17, 24, 25, 20};
    vector<int> b = {55, 99, 61, 99, 91, 90, 98, 30, 25, 30, 29};
    string p = "";
    for (int i = 0; i < a.size(); ++i) {
        char c = a[i] + b[i];
        p += c;
    }
    cout << p << endl;

    return 0;
}