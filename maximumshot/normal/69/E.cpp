#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define what(x) cerr << #x << " = " << x << '\n';
#define mp make_pair
#define vec vector

typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;

map<LL, int> C;
set<LL> s;

bool solve()
{
    int n, k;

    cin >> n >> k;

    vec<LL> a(n);

    for(int i(0);i < n;i++)
        cin >> a[i];
    
    for(int i(0);i < k;i++)
        C[a[i]]++;

    for(int i(0);i < k;i++)
        if(C[a[i]] == 1) s.insert(a[i]);
    
    if(!s.empty() )cout << *(--s.end()) << '\n';
    else cout << "Nothing\n";

    for(int i(k);i < n;i++)
    {
        C[a[i - k]]--;
        if(C[a[i - k]] == 1) s.insert(a[i - k]);
        else s.erase(a[i - k]);

        C[a[i]]++;

        if(C[a[i]] == 1) s.insert(a[i]);
        else s.erase(a[i]);

        if(s.empty()) cout << "Nothing\n";
        else cout << *(--s.end()) << '\n';
    }

    return true;
}

int main()
{
    //while(solve()) {}
    solve();

    return 0;
}