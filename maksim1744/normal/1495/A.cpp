/** Hanabi?
**                                .
**                              .'
**                            .'
**                            /`-._'
**                           /   /
**                          /   /
**                         /   /
**                        (`-./
**                         )
**                        '       .
**                              .'
**                            .'
**                            /`-._'
**                           /   /
**                          /   /
**                         /   /
**                        (`-./
**                         )
**                        '
**/
//Kaicho Shirogane Miyuki
//Grieveous lady Shinomiya Kaguya
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define alla(a,n) a, a + n
#define endstring std::string::npos
#define prtarr(n,len) {for(int i=0;i<len;i++) cout<<n[i]<<" "; cout<<"\n";}
#define prtarrr(n,len) {for(int i=len - 1;i>=0;i--) cout<<n[i]<<" "; cout<<"\n";}
#define prtset(n) {for(auto i:n) cout<<i<<" "; cout<<"\n";}
#define prtpair(n) {cout<<n.fr<<" "<<n.sc<<"\n";}
#define judge(a) {if(a) cout<<"YES"<<"\n"; else cout<<"NO"<<"\n";}
#define search(a,n) a.find(n)
#define Ataru main
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<vi> vvii;
typedef vector<string> vs;
using namespace std;
int inquire(int x,int y){
    cout<<"? "<<x<<" "<<y<<endl;
    int a; cin>>a;
    return a;
}
const ll INF= 1e18;
const ll MAX=1e5 + 10;
const ll LOG_MAX = 20;
const double pi = 3.141592653;


int cases, n;
int Ataru(){
    //freopen("input.txt", "r", stdin) ;
    //freopen("output.txt", "w", stdout) ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    std::cout<<std::setprecision(9)<<std::fixed;
    cin >> cases;
    while(cases--){
        cin >> n;
        vector<double> miner;
        vector<double> mine;
        for(int i = 0; i < 2 * n; i++){
            int x, y; cin >> x >> y;
            if(x == 0.0) miner.pb(abs(y));
            if(y == 0.0) mine.pb(abs(x));
        }
        sort(all(miner));
        sort(all(mine));
        //prtarr(miner,(int)miner.size());
        //prtarr(mine,(int)mine.size());
        double ans = 0.0;
        for(int i = 0; i < (int)miner.size(); i++){
            //int p2 = (int)miner.size() - i - 1;
            //cout << p2 << " " << (miner[i] * miner[i]) + (mine[p2] * mine[p2]) << "\n";
            ans += (double)(sqrt((miner[i] * miner[i]) + (mine[i] * mine[i])));
        }
        cout << ans << "\n";
    }
    return 0;
}