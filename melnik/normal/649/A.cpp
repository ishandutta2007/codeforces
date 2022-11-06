#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define int long long
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)
#define pii pair<int,int>


const int maxn = 1e5+500;
const int inf = 1e9;
const double eps = 1e-7;
const int base = 1073676287;
using namespace std;

void bad(){ puts("-1"), exit(0); }

main()
{
    map<int,int> mp;
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        int mx = 1;
        int st = 1;
        for (; st <= inf; st *= 2){
            if (x % st == 0){
                mx = st;
            }
        }
        mp[mx] ++ ;
    }
    auto j = mp.end();
    --j;
    cout << j->first <<' ' << j->second;
}