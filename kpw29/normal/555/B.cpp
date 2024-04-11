#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> BONG;
typedef pair <ll, ll> LONG;
typedef pair <ld, ld> DONG;
typedef pair <BONG, BONG> PAIR;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,c,p,q, k;
ll N,M,P,Q,A,B,C;
int x;
pair <ll, ll> t[milion];
pair <ll, int> br[milion];
vector <pair <pair <ll, ll>, int> > v;
multiset <pair <ll, int> > s;
int wyn[milion];
#define OUT(x) {cout << x; return 0;}
int main()
{
    boost;
    cin >> n >> k;
    if (n == 1) OUT("Yes");
    for (int i=1; i<=n; ++i) 
    {
        cin >> t[i].e1 >> t[i].e2;
        if (i - 1)
        {
            v.push_back(mp( mp(t[i].e2 - t[i-1].e1, t[i].e1 - t[i-1].e2), i - 1));
        }
    }
    
    for (int i=1; i<=k; ++i) 
    {
        cin >> br[i].e1;
        br[i].e2 = i;
        s.insert(br[i]);
    }
    
    sort(v.begin(), v.end());

    for (ui i=0; i<v.size(); ++i) swap(v[i].e1.e1, v[i].e1.e2);
    
    //for (ui i=0; i<v.size(); ++i) cout << v[i].e1.e1 << ' ' << v[i].e1.e2 << endl;
    for (ui i=0; i<v.size(); ++i)
    {
        multiset <pair <ll, int> > ::iterator el = s.lower_bound(mp(v[i].e1.e1, -inf));
        if (el == s.end()) OUT("No");
        pair <ll, int> w = *el;
        s.erase(el);
        if (w.e1 > v[i].e1.e2) OUT("No");
        wyn[v[i].e2] = w.e2;
    }
    cout << "Yes" << endl;
    for (int i=1; i<n; ++i) cout << wyn[i] << ' ';
    return 0;
}