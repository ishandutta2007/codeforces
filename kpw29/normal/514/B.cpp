#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> BONG;
typedef unsigned int ui;
const int inf = 1e9+9;


int n,m,a,b, x, y;
string s;
vector <BONG> v;

int main()
{
    int n;
    scanf("%d%d%d", &n, &x, &y);
    for (int i=0; i<n; ++i)
    {
        scanf("%d%d", &a, &b);
        a-=x;
        b-=y;
        int dziel = __gcd(a,b);
        a /= dziel;
        b /= dziel;
        v.push_back(make_pair(a,b));
    }
    sort (v.begin(), v.end());
    int wyn =1;
    for (int i=1; i<v.size(); ++i)
    {
        if (v[i].first != v[i-1].first || v[i-1].second != v[i].second) ++wyn;
    }
    printf("%d", wyn);
}