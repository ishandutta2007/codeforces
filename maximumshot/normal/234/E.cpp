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
#include <list>
#include <cstring>

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

void erase(vec< int > & a, int x) {
    vec<int> ans;
    int n = (int)a.size();
    for(int i = 0;i < x;i++) ans.push_back(a[i]);
    for(int i = x + 1;i < n;i++) ans.push_back(a[i]);
    a = ans;
}

int n, x, a, b, c;
vec< string > name;
vec< int > rating, mas;

bool cmp(int p1, int p2) {
    return (rating[p1] > rating[p2]);
}

bool solve()
{   
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> x >> a >> b >> c;   
    
    for(int i = 0;i < n;i++) {
        string s;
        int val;
        cin >> s >> val; 
        name.push_back(s);
        rating.push_back(val);
        mas.push_back(i);
    }

    sort(ALL(mas), cmp);

    int cc = 0, len = n / 4;

    vec< int > t[4];

    for(int i = 0;i < n;i++) {
        t[i / len].push_back(mas[i]);
    }
    
    for(int hh = 0;hh < len;hh++) {
        cout << "Group " << char(cc + 'A') << ":\n";
        for(int i = 0;i < 4;i++) {
            x = (x * a + b) % c;
            int id = t[i][x % (int)t[i].size()];
            cout << name[id] << '\n';
            erase(t[i], x % (int)t[i].size());
        }
        cc++;
    }

    return true;
}  

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}