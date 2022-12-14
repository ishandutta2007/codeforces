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


#include<vector>

struct SegmentTreeSum
{
    int sz;
    std::vector<long long> tree;
    std::vector<int> tempr;


    SegmentTreeSum() {}

    SegmentTreeSum(int _sz)
    {
        sz = _sz;
        tree.assign(4 * sz, 0);
    }

    void build(int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = tempr[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }

    SegmentTreeSum(const std::vector<int>& dt)
    {
        sz = dt.size();
        tree.assign(4 * sz, 0);
        tempr = dt;
        build(1, 0, sz - 1);
    }

    long long query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 0;
		if (tl >= l && tr <= r)
            return tree[v];

        int tm = (tl + tr) / 2;

        return query(v * 2, tl, tm, l, std::min(r, tm)) +
               query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r);
    }

    inline long long Query(int l, int r)
    {
        return query(1, 0, sz - 1, l, r);
    }

    void update(int v, int tl, int tr, int id, int val)
    {
        if (tr < id) return;
        if (id < tl) return;
		if (tl == id && tr == id)
        {
			tree[v] += val;
			return;
		}

		int tm = (tl + tr) / 2;
        update (v * 2, tl, tm, id, val);
        update (v * 2 + 1, tm + 1, tr, id, val);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }

    inline void Update(int id, int val)
    {
        update(1, 0, sz - 1, id, val);
    }
};

#include<vector>

struct SegmentTreeMin
{
    int sz;
    std::vector<long long> tree;
    std::vector<int> tempr;


    SegmentTreeMin() {}

    SegmentTreeMin(int _sz)
    {
        sz = _sz;
        tree.assign(4 * sz, 0);
    }

    void build(int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = tempr[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }

    SegmentTreeMin(const std::vector<int>& dt)
    {
        sz = dt.size();
        tree.assign(4 * sz, 0);
        tempr = dt;
        build(1, 0, sz - 1);
    }

    long long query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return LLONG_MAX;
		if (tl >= l && tr <= r)
            return tree[v];

        int tm = (tl + tr) / 2;

        return min(query(v * 2, tl, tm, l, std::min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
    }

    inline long long Query(int l, int r)
    {
        return query(1, 0, sz - 1, l, r);
    }

    void update(int v, int tl, int tr, int id, int val)
    {
        if (tr < id) return;
        if (id < tl) return;
		if (tl == id && tr == id)
        {
			tree[v] = val;
			return;
		}

		int tm = (tl + tr) / 2;
        update (v * 2, tl, tm, id, val);
        update (v * 2 + 1, tm + 1, tr, id, val);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }

    inline void Update(int id, int val)
    {
        update(1, 0, sz - 1, id, val);
    }
};

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define psum(x) ((x).first + (x).second)
#define ft first
#define sd second
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define log(x) //cout << "logging: value of '" << #x << "' = " << x << "." << endl


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;

     string s;
     cin >> s;

    vi sm(n, 0);
    for (int i = 0; i < n; ++i)
    {
        if (i>0)
            sm[i] = sm[i-1];
        if (s[i] == '(')
                sm[i]++;
        else
            sm[i]--;
    }




    SegmentTreeSum suff(2*n+2);
    SegmentTreeSum suffn(2*n+2);

    ll suml = 0;
    ll csum = 0;
    int num = 1;

    stack<int> st;
    st.push(1);


    for (int i = n-1; i >= 0; --i)
    {
        ll val = sm[i];


        if (s[i] == ')')
        {
            csum += num;
            st.push(1);
        }
        else
        {
            csum -= num;
            log(num);


            int sttop = st.top();
            st.pop();
            csum += sttop;
            log(sttop);
            sttop++;
            if (st.empty())
                st.push(sttop);
            else
            {
                int nt = st.top();
                st.pop();
                st.push(sttop+nt);
            }


            //csum += it.sd;
        }

        log(csum);
        ++num;

        suml += csum;
    }

    SegmentTreeSum sufh(2*n+2);
    SegmentTreeSum sufhn(2*n+2);

    ll sumr = 0;

    for (int i = n-1; i >= 0; --i)
    {
        ll val = sm[i];
        ll pos = sm[i] + n;

        sumr += - val*sufhn.Query(pos+1, 2*n+1) + sufh.Query(pos+1, 2*n+1);

        sufh.Update(pos, val);
        sufhn.Update(pos, 1);
    }
    ll val = 0;
    ll pos = n;
    sumr += - val*sufhn.Query(pos+1, 2*n+1) + sufh.Query(pos+1, 2*n+1);

    ans = 0;
    ans = sumr;

    ll as = suml;

    log(suml);
    log(sumr);






    ans += as;




    cout << ans << endl;

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