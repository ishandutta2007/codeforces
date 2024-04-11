#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pii>;
using vpll = vector<pll>;

template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.first << ' ' << x.second;}
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.first >> x.second;}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};


#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define psum(x) ((x).first + (x).second)
#define ft first
#define sd second
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl


#include <vector>


struct SNM
{
    std::vector<int> groupID;
    std::vector<std::vector<int>> group;
    std::vector<int> vls;

    SNM(int sz)
    {
        group.resize(sz);
        groupID.resize(sz);
        vls.assign(sz, 1);

        for (int i = 0; i < sz; ++i)
        {
            group[i] = {i};
            groupID[i] = i;
        }
    }

    int Get(int id)
    {
        return vls[groupID[id]];
    }

    void Merge(int id1, int id2)
    {
        id1 = groupID[id1];
        id2 = groupID[id2];

        if (id1 == id2) return;

        if (group[id1].size() < group[id2].size())
            std::swap(id1, id2);

        //vls[id1] = <merge(val1, val2)>;

        for (int i = 0; i < group[id2].size(); ++i)
        {
            int nt2 = group[id2][i];
            groupID[nt2] = id1;
            group[id1].push_back(nt2);
        }

        group[id2] = std::vector<int>();
    }
};

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;

    vi dt(n);
    vi used(n, 0);
    cin >> dt;

    vpii ord(n);

    for (int i = 0; i < n; ++i)
    {
        ord[i] = {dt[i], i};
    }

    SNM snm(n);

    sort(all(ord));

    for (int id = n-1; id >= 0; --id)
    {
        int cur = ord[id].sd;
        int cursz = ord[id].ft;

        if (used[cur] != 0)
            continue;
        used[cur] = true;

        for (int i = 0; i < cursz; ++i)
        {
            int next;
            cout << "? " << cur + 1 << endl;
            cin >> next;
            --next;

            snm.Merge(cur, next);

            if (used[next] != 0)
                break;
            used[next] = true;
        }
    }

    for (int i = 0; i < snm.groupID.size(); ++i)
    {
        snm.groupID[i]++;
    }


    cout << "! " << snm.groupID << endl;


    return 0;
}


int main()
{
    FAST;

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}