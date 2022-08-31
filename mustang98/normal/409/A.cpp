#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string a, b;
    cin >> a;
    cin >> b;
    int sc = 0;
    int cnt = 0;
    for (int i = 0; i < a.size(); i += 2) {
        if (a[i] == '8' && b[i] == '[') {
            ++cnt;
        }
        if (a[i] == '[' && b[i] == '8') {
            --cnt;
        }
        if (a[i] == '[' && b[i] == '(') {
            ++cnt;
        }
        if (a[i] == '(' && b[i] == '[') {
            --cnt;
        }
        if (a[i] == '(' && b[i] == '8') {
            ++cnt;
        }
        if (a[i] == '8' && b[i] == '(') {
            --cnt;
        }
    }
    if (cnt < 0) {
        cout << "TEAM 2 WINS" << endl;
    } else if (cnt > 0) {
        cout << "TEAM 1 WINS" << endl;
    } else {
        cout << "TIE";
    }


    return 0;
}