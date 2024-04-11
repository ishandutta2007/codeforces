#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef bitset<120> mask;
// typedef int64 mask;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int to[120][120];
map<vector<int>,int> perm_ix;

vector<int> apply(vector<int> a, vector<int> b){
    vector<int> c(a.size());

    for (int i = 0; i < (int)a.size(); ++i){
        c[i] = a[b[i]];
    }
    return c;
}

void show(vector<int> &a){
    cout << "P:";
    for (auto x : a)
        cout << " " << x;
    cout << endl;
}

void generate_matrix(int k){
    vector<int> a(k);
    iota(a.begin(), a.end(), 0);
    int a_ix = 0;

    do{
        perm_ix[a] = a_ix;
        ++a_ix;
    } while (next_permutation(a.begin(), a.end()));

    a_ix = 0;

    do{
        vector<int> b(k);
        iota(b.begin(), b.end(), 0);
        int b_ix = 0;

        do{
            auto c = apply(a, b);
            to[a_ix][b_ix] = perm_ix[c];
            ++b_ix;
        } while (next_permutation(b.begin(), b.end()));

        ++a_ix;
    } while (next_permutation(a.begin(), a.end()));
}

// const int big = (1 << 30) - 1;

namespace std {
    template<std::size_t N>
    bool operator<(const std::bitset<N>& x, const std::bitset<N>& y)
    {
        for (int i = N-1; i >= 0; i--) {
            if (x[i] ^ y[i]) return y[i];
        }
        return false;
    }
}

int count128(mask total) {
    return total.count();
}

const mask one = 1;

map<pair<mask,int>,mask> memo;

mask merge(mask m, int u){
    if (m.test(u))
        return m;

    auto cur = make_pair(m, u);
    if (memo.find(cur) != memo.end())
        return memo[cur];

    vector<int> active;
    for (int i = 0; i < 120; ++i)
        if (m.test(i))
            active.push_back(i);

    int pnt = active.size();
    active.push_back(u);

    while (pnt < active.size()){
        int u = active[pnt++];

        for (int i = 0; i < pnt; ++i){
            for (auto p : {pii(active[i], u), pii(active[i], u)}){
                int v = to[p.first][p.second];

                if (m.test(v))
                    continue;

                m.set(v);
                active.push_back(v);
            }
        }
    }

    memo[cur] = m;
    return m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;

    generate_matrix(k);
    vector<mask> ONE(perm_ix.size());

    for (int i = 0; i < (int)perm_ix.size(); ++i){
        ONE[i] = merge(1, i);
    }

    int64 answer = 0;

    vector<int> val(n);
    vector<pair<mask,int>> prefix;


    for (int i = 0; i < n; ++i){
        vector<int> p(k);

        for (int j = 0; j < k; ++j){
            cin >> p[j]; p[j]--;
        }

        val[i] = perm_ix[p];

        vector<pair<mask,int>> new_prefix;

        int last = 0;

        for (auto v : prefix) {
            mask cur = merge(v.first, val[i]);

            answer += count128(cur) * (v.second - last);
            last = v.second;

            if (!new_prefix.empty() && new_prefix.back().first == cur)
                new_prefix.back().second = last;
            else
                new_prefix.push_back({cur, last});
        }

        // last
        // mask cur = merge(1, val[i]);
        mask cur = ONE[val[i]];

        answer += count128(cur) * (i + 1 - last);
        last = i + 1;

        if (!new_prefix.empty() && new_prefix.back().first == cur)
            new_prefix.back().second = last;
        else
            new_prefix.push_back({cur, last});

        prefix.swap(new_prefix);
    }

    cout << answer << endl;

    return 0;
}