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


struct Node
{
    int mn;
    int mx;
    int adds;
    unique_ptr<Node> Lid;
    unique_ptr<Node> Rid;

    Node(int l, int r, int add)
    {
        mn = l;
        mx = r;
        adds = add;
        Lid = nullptr;
        Rid = nullptr;
    }

    pii Get()
    {
        return {mn+adds, mx+adds};
    }

    void Update()
    {
        mn = Lid->mn+Lid->adds;
        mx = Rid->mx+Rid->adds;
    }

    void Push()
    {
        Lid->adds += adds;
        Rid->adds += adds;
        adds = 0;
        Update();
    }

    int query(int tl, int tr, int pos)
    {
        if (Lid == nullptr)
            return pos + adds;

        Push();
        int tm = (tl+tr)/2;
        if (pos <= tm)
            return Lid->query(tl, tm, pos);
        else
            return Rid->query(tm+1, tr, pos);
    }

    void update(int tl, int tr, int pos)
    {
        //cout << "update tl[" << tl << "] tr[" << tr << "] pos[" << pos << "]" << endl;
        pii lims = Get();
        if (lims.ft == pos && lims.sd == pos)
            return;
        if (lims.ft > pos && lims.sd > pos)
        {
            adds--;
            return;
        }
        if (lims.ft < pos && lims.sd < pos)
        {
            adds++;
            return;
        }

        int tm = (tl+tr)/2;

        //log(tm);
        //log(node->Lid);

        if (Lid == nullptr)
        {
            //cout << "creating " << endl;
            //Node* lnode = new Node(tl, tm, 0);
            Lid = unique_ptr<Node>(new Node(tl, tm, 0));
            //Node* rnode = new Node(tm+1, tr, 0);
            Rid = unique_ptr<Node>(new Node(tm+1, tr, 0));
        }


        Push();

        Lid->update(tl, tm, pos);
        Rid->update(tm+1, tr, pos);

        Update();
    }

};

struct Tree
{
    unique_ptr<Node> tree;

    Tree()
    {
        tree = unique_ptr<Node>(new Node(0, 1000000000, 0));
    }



    int Get(int pos)
    {
        return tree->query(0, 1000000000, pos);
    }


    void Update(int val)
    {
        tree->update(0, 1000000000, val);
    }
};

long long a, b, m, tmp, ans = 0;



int solve()
{
    int n;
    cin >> n;

    Tree tree;

    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        tree.Update(val);

        int k;
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            int q;
            cin >> q;
            q += ans;
            q %= 1000000001;

            ans = tree.Get(q);
            cout << ans << endl;
        }
    }



    return 0;
}


int main()
{
    FAST;

    solve();

    return 0;
}