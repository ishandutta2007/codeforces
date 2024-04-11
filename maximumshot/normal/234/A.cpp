#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <iomanip>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0);

using namespace std;

bool solve()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    string s;

    cin >> s;

    vec< pair<int, int> > ans;

    if(n % 4 == 0) {
        for(int j = 0;j < 2;j++) {
            for(int i = j;i + 2 < n;i += 4) {
                // i . i + 2
                int l, r;
                l = i, r = i + 2;
                if(s[l] == 'R' && s[r] == 'L') swap(l, r);
                cout << l + 1 << ' ' << r + 1 << '\n';
            }
        }
    }else {
        for(int j = 1;j < 3;j++) {
            for(int i = j;i + 2 < n;i += 4) {
                // i . i + 2
                int l, r;
                l = i, r = i + 2;
                if(s[l] == 'R' && s[r] == 'L') swap(l, r);
                cout << l + 1 << ' ' << r + 1 << '\n';
            }
        }
        int l, r;
        l = 0, r = n - 1;
        if(s[l] == 'R' && s[r] == 'L') swap(l, r);
        cout << l + 1 << ' ' << r + 1 << '\n';  
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}