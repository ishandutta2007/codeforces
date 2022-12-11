#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>


using namespace __gnu_pbds;
using namespace std;


#define debug(...) 42


using ll = long long;


using vi = vector<int>;


#define bg(x) begin(x)
#define all(x) bg(x), end(x)


#define pb push_back


#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)


#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);


/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

/*
vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k)
{
    if (k < 0 || k > n)
    {
        return 0;
    }
    while ((int)fact.size() < n + 1)
    {
        fact.push_back(fact.back() * (int)fact.size());
        inv_fact.push_back(1 / fact.back());
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}
*/
 // (int)1e9 + 7;


const int MN = (int)2e5 + 5;
const ll INF = 1e9;

map<string, int> day_map;
int working_day[MN];
vi holidays[7];

// this is NOT a multiset. Use pair<int, int> for multiset
using ordered_set = tree<int, null_type, less<int>,
                         rb_tree_tag, tree_order_statistics_node_update>;

ordered_set reserved[MN];

int get_scheduled_days(int st, int en, int employee)
{
    int res = 0;
    F0R(i, 7)
    {
        if ((working_day[employee] & (1 << i)) == 0)
            continue;
        int s = st;
        if (s % 7 > i)
            s += 7 + i - s % 7;
        else if (s % 7 < i)
            s += i - s % 7;

        int e = en;
        if (e % 7 > i)
            e -= e % 7 - i;
        else if (e % 7 < i)
            e -= 7 + e % 7 - i;
        res += (e - s + 7) / 7;
    }
    return res;
}

int get_scheduled_holidays(int st, int en, int employee)
{
    int res = 0;
    F0R(i, 7)
    {
        if ((working_day[employee] & (1 << i)) == 0)
            continue;
        res += upper_bound(all(holidays[i]), en) - lower_bound(all(holidays[i]), st);
    }
    return res;
}

int find_working_day(int st, int employee)
{
    int s = st, e = INF;
    while (s < e)
    {
        int m = (s + e) / 2;
        // if (st = 1 && employee == 1)
        // {
        //     debug(s, e, m);
        //     debug(get_scheduled_days(1, 6, 1));
        // }
        int sum = get_scheduled_days(st, m, employee) - get_scheduled_holidays(st, m, employee);
        sum -= reserved[employee].order_of_key(m + 1) - reserved[employee].order_of_key(st);
        if (sum)
            e = m;
        else
            s = m + 1;
    }
    return s;
}

int main()
{
    FAST_IO;
    int n, m, k;
    cin >> n >> m >> k;

    day_map["Monday"] = 1;
    day_map["Tuesday"] = 2;
    day_map["Wednesday"] = 3;
    day_map["Thursday"] = 4;
    day_map["Friday"] = 5;
    day_map["Saturday"] = 6;
    day_map["Sunday"] = 0;

    FOR(i, 1, n + 1)
    {
        int t;
        cin >> t;
        while (t--)
        {
            string s;
            cin >> s;
            working_day[i] += 1 << day_map[s];
        }
    }
    while (m--)
    {
        int x;
        cin >> x;
        holidays[x % 7].pb(x);
    }
    debug(get_scheduled_days(1, 6, 1));
    debug(get_scheduled_days(1, 7, 1));
    debug(get_scheduled_holidays(1, 6, 1));
    debug(get_scheduled_holidays(1, 7, 1));
    while (k--)
    {
        int p;
        cin >> p;
        int st = 1;
        while (p--)
        {
            int employee;
            cin >> employee;
            int day = find_working_day(st, employee);
            reserved[employee].insert(day);
            debug(k, p, day);
            st = day + 1;
        }
        cout << st - 1 << ' ';
    }
}