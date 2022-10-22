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

int get(vec< int > a) {
    return unique(ALL(a)) - a.begin();
}

bool solve()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    vec< int > a, b;
    cin >> n;
    a.resize(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    cin >> m;
    b.resize(m);
    for(int i = 0;i < m;i++) cin >> b[i];

    int c1, f1, c2, f2;

    c1 = get(a);
    f1 = a[0];

    c2 = get(b);
    f2 = b[0];

    vec< vec< int > > ans;

    if(f1 == 0) {
        if(f2 == 0) {
            vec< int > c;
            for(int z = 0, j = 0, i = 0;;) {
                if(i == n && j == m) break;
                while(i < n && a[i] == z) c.push_back(i + 1), i++;
                while(j < m && b[j] == z) c.push_back(n + j + 1), j++;
                z ^= 1;
            }
            ans.push_back(c);
        }else {
            vec< int > c;
            for(int z = 0, j = 0, i = 0;;) {
                if(i == n && j == m) break;
                while(i < n && a[i] == z) c.push_back(i + 1), i++;
                while(j < m && b[j] == z) c.push_back(n + j + 1), j++;
                z ^= 1;
            }
            ans.push_back(c);
            c.clear();
            for(int z = 1, j = 0, i = 0;;) {
                if(i == n && j == m) break;
                while(i < n && a[i] == z) c.push_back(i + 1), i++;
                while(j < m && b[j] == z) c.push_back(n + j + 1), j++;
                z ^= 1;
            }
            ans.push_back(c);
        }
    }else {
        if(f2 == 1) {
            vec< int > c;
            for(int z = 1, j = 0, i = 0;;) {
                if(i == n && j == m) break;
                while(i < n && a[i] == z) c.push_back(i + 1), i++;
                while(j < m && b[j] == z) c.push_back(n + j + 1), j++;
                z ^= 1;
            }
            ans.push_back(c);
        }else {
            vec< int > c;
            for(int z = 0, j = 0, i = 0;;) {
                if(i == n && j == m) break;
                while(i < n && a[i] == z) c.push_back(i + 1), i++;
                while(j < m && b[j] == z) c.push_back(n + j + 1), j++;
                z ^= 1;
            }
            ans.push_back(c);
            c.clear();
            for(int z = 1, j = 0, i = 0;;) {
                if(i == n && j == m) break;
                while(i < n && a[i] == z) c.push_back(i + 1), i++;
                while(j < m && b[j] == z) c.push_back(n + j + 1), j++;
                z ^= 1;
            }
            ans.push_back(c);
        }
    }

    int id = -1, vval = inf;
    for(int i = 0;i < (int)ans.size();i++) {
        int tmp = 0;
        for(int j = 0;j < (int)ans[i].size();j++) {
            int q = j, id = ans[i][j];
            int value = (id <= n?a[id - 1] : b[id - 1 - n]);
            while(q < (int)ans[i].size()) {
                int iid = ans[i][q];
                int vvalue = (iid <= n?a[iid - 1] : b[iid - 1 - n]);
                if(value == vvalue) q++;
                else break;
            }
            q--;
            tmp++;
            j = q;
        }
        int idlast = ans[i].back();
        int last = (idlast <= n?a[idlast - 1] : b[idlast - 1 - n]);
        if(last == 0) tmp--;
        if(vval > tmp) {
            vval = tmp;
            id = i;
        }
    }

    vec< int > val;
    for(int i = 0;i < (int)ans[id].size();i++) {
        int j = ans[id][i];
        cout << j << ' ';
        if(j <= n) val.push_back(a[j - 1]);
        else val.push_back(b[j - n - 1]);
    }

    cout << '\n';

    cout << vval << '\n';

    if(val.back() == 1) val.push_back(0);

    for(int i = 0;i + 1 < (int)val.size();i++) {
        if(val[i] != val[i + 1]) {
            cout << i + 1 << ' ';
        }
    }

    cout << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}