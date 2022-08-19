#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define nl cout<<"\n"
#define all(x) x.begin(),x.end()

template<class C> void min_self( C &a, C b ){ a = min(a,b); }
template<class C> void max_self( C &a, C b ){ a = max(a,b); }

const ll MOD = 1000000007;
// const ll MOD = 998244353;
template<class T1, class T2> void add( T1 &x, T2 y, ll m = MOD ){ x += y; if( x >= m ) x -= m; }
template<class T1, class T2> void sub( T1 &x, T2 y, ll m = MOD ){ x -= y; if( x < 0 ) x += m; }
ll mod( ll n, ll m=MOD ){ n%=m;if(n<0)n+=m;return n; }

const int MAXN = 1e5+5;
const int LOGN = 21;
const ll INF = 1e16;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

class FenwickTree
{
public:
    int N;
    vector<int> tree;
    FenwickTree(int n)
    {
        N = n+5;
        tree.clear();
        tree.resize(N,0);
    }
    void update( int pos, int add )
    {
        pos += 2;
        while( pos < N )
        {
            tree[pos] += add;
            pos += pos & -pos;
        }
    }
    int get( int pos )
    {
        pos += 2;
        int ans = 0;
        while( pos > 0 )
        {
            ans += tree[pos];
            pos -= pos & -pos;
        }
        return ans;
    }
};

void solve()
{
    // vector<char> perm = {'A','N','O','T'};
    vector<char> perm = {'A','B','C','D'};

    string s;
    cin>>s;
    for (char &c : s) {
        if (c == 'N') c = 'B';
        else if (c == 'O') c = 'C';
        else if (c == 'T') c = 'D';
    }

    int n = s.size();

    vector<ll> cnt(4,0);
    for(int i=0;i<n;i++)
        cnt[s[i]-'A']++;

    auto cost = [&](string &a, string &aa)
    {
        int ptr = 0;
        ll ans = 0;
        string tempaa = aa;

        deque<int> pos[4];
        FenwickTree ft(n);
        for(int i=0;i<n;i++)
        {
            pos[aa[i]-'A'].push_back(i);
            ft.update(i,1);
        }

        for(int i=0;i<n && ptr < n;)
        {
            if( aa[i] == 'a' )
            {
                i++;
                continue;
            }

            // int j = i;
            // ll how_many = 0;
            // for(j=i;j<n;j++)
            // {
            //     if( aa[j] == a[ptr] )
            //     {
            //         aa[j] = 'a';
            //         break;
            //     }
            //     if( aa[j] != 'a' )
            //         how_many++;
            // }

            int now = a[ptr]-'A';
            int j = pos[now].front();
            pos[now].pop_front();
            aa[j] = 'a';
            ft.update(j,-1);
            ll how_many = ft.get(j);

            ans += how_many;
            ptr++;
        }
        aa = tempaa;
        return ans;
    };

    string ans = s;
    ll best = 0;

    do
    {
        string ss = "";
        for( auto x : perm )
            ss += string(cnt[x-'A'],x);

        ll now = cost(s,ss);

        if( now > best )
        {
            best = now;
            ans = ss;
        }

    }while( next_permutation(all(perm)) );

    for (char &c : ans) {
        if (c == 'B') c = 'N';
        else if (c == 'C') c = 'O';
        else if (c == 'D') c = 'T';
    }

    cout<<ans,nl;
}

int main()
{
    #ifdef gupta_samarth
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastio();

    int t = 1;
    cin>>t;
    for(int test=1;test<=t;test++)
    {
        // cout<<"Case #"<<test<<": ";
        solve();
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}