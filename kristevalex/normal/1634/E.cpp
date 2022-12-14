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


vector<vpii> data;
vector<set<pii>> st;
vector<set<int>> has;

long long a, b, k, n, m, tmp;

vvi ans;

#include <vector>
#include <algorithm>

inline std::vector<int> Compress(const std::vector<int>& arr)
{
    const int arraySize = arr.size();
    std::vector<std::pair<int, int>> indexedArr(arraySize);
    std::vector<int> ret(arraySize);

    for (int i = 0; i < arraySize; ++i)
        indexedArr[i] = {arr[i], i};
    sort(indexedArr.begin(), indexedArr.end());

    int curId = 0;
    for (int i = 0; i < arraySize; ++i)
    {
        ret[indexedArr[i].second] = curId;
        if (i+1 < arraySize && indexedArr[i].first != indexedArr[i+1].first)
            ++curId;
    }

    return ret;
}

void print()
{
    cendl;
    cout << "print: \n";
    for (int i = 0; i < n; ++i)
    {
        cout << i << "|= ";
        for (auto it = st[i].begin(); it != st[i].end(); ++it)
        {
            cout << " {" << it->ft << " " << it->sd << "} ";
        }
        cendl;
    }
    cout << "has: \n";
    for (int i = 0; i < has.size()-8; ++i)
    {
        cout << i << "|= ";
        for (auto it = has[i].begin(); it != has[i].end(); ++it)
        {
            cout << (*it) << " ";
        }
        cendl;
    }
    cendl;
    cendl;

}

int solve()
{
    cin >> n;

    ::data.resize(n);
    ::ans.resize(n);
    ::st.resize(n);

    vi total;


    for (int i = 0; i < n; ++i)
    {
        cin >> m;
        ::data[i].resize(m);
        ::ans[i].resize(m);
        for (int j = 0; j < m; ++j)
        {
            cin >> tmp;
            total.pb(tmp);
        }

    }

    has.resize(total.size()+10);


    total = Compress(total);
    int totid = 0;



    for (int i = 0; i < n; ++i)
    {
        //log(i);
        for (int j = 0; j < ::data[i].size(); ++j)
        {
            //log(j);
            //log(totid);

            ::data[i][j] = {total[totid++], j};
        }
        //log(i);

        sort(all(::data[i]));
        for (int j = 0; j < ::data[i].size(); ++j)
        {
            //log(j);
            if (j+1 < ::data[i].size())
            {
                if (::data[i][j].ft == ::data[i][j+1].ft)
                {
                    ans[i][::data[i][j].sd] = 1;
                    ans[i][::data[i][j+1].sd] = 0;
                    ++j;
                    continue;
                }
            }
            //log(j);

            st[i].insert(::data[i][j]);
            has[::data[i][j].ft].insert(i);
        }
        //log(i);
    }


    for (int i = 0; i < has.size(); ++i)
    {
        if (has[i].size()%2 != 0)
        {
            cno;
            return 0;
        }
    }

    //log("hi");

    int cnt  =0;
    //print();

    for (int id = 0; id < n; ++id)
    {
        while(!st[id].empty())
        {
            ++cnt;
            //cendl;
            //log(cnt);
            auto it1 = st[id].begin();
            auto it2 = it1;
            it2++;

            int L = it1->ft;
            int R = it2->ft;

            ans[id][it1->sd] = 0;
            ans[id][it2->sd] = 1;

            st[id].erase(it1);
            st[id].erase(it2);
            has[L].erase(id);
            has[R].erase(id);
            //print();

            while(L != R)
            {
                int nextid = *(has[L].begin());
                auto it2_ = st[nextid].upper_bound({L, -2});
                auto it1_ = it2_;
                it1_++;
                if (it1_ == st[nextid].end())
                    it1_ = st[nextid].begin();

                int L_ = it1_->ft;
                int R_ = it2_->ft;

                ans[nextid][it1_->sd] = 0;
                ans[nextid][it2_->sd] = 1;

                st[nextid].erase(it1_);
                st[nextid].erase(it2_);
                has[L_].erase(nextid);
                has[R_].erase(nextid);

                L = L_;
                /*print();
                log(L);
                log(R);
                log(L_);
                log(R_);*/
            }
        }
    }


    cyes;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
        {
            if (ans[i][j])
                cout << "R";
            else
                cout << "L";
        }
        cendl;
    }

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}