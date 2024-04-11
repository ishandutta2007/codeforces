#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define F first
#define S second
#define dec lol
#define pb push_back
#define mp make_pair

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;

const int max_n = 200111, mod = 1000000007, max_sqrt = 450;

pair<int, int> q[max_n / 4];

int m[max_n];
int n, qnum;
bool used[max_n];
int pos[max_n];
int ansq[max_n];
int add[max_n];
int val[max_n];
int dec[max_n];
int kor;


struct query
{
    int l, r, base, ind, mult;
    query(int a, int b, int c, int d, int e) {
        l = a;
        r = b;
        base = c;
        ind = d;
        mult = e;
    }
};

bool operator < (const query &q1, const query &q2)
{
    return q1.base < q2.base;
}

vector<int> active;

void set_bit(int ind) {
    val[ind] = 1;
    dec[ind / kor]++;
}

int get_sum(int l, int r) {
    if (l > r) return 0;
    int block1 = l / kor, block2 = r / kor;
    int ans = 0;
    if (block1 == block2) {
        for (int i = l; i <= r; ++i) {
            ans += val[i];
        }
        return ans;
    }
    while(l / kor == block1) {
        ans += val[l];
        ++l;
    }
    while(r / kor == block2) {
        ans += val[r];
        --r;
    }
    for (int i = block1 + 1; i < block2; ++i) {
        ans += dec[i];
    }
    return ans;
}

void solve(int from, int to) {
    //cout << from << ' ' << to << endl;
    for (int i = 0; i < n; ++i) {
        used[i] = false;
        pos[m[i]] = i;
        dec[i] = val[i] = 0;
    }
    active.clear();
    for (int i = from; i <= to; ++i) {
        used[m[q[i].S]] = used[m[q[i].F]] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            active.push_back(i);
     //       cout << i << ' ';
        }
    }
    vector<query> v;
    for (int i = from; i <= to; ++i) {
        int l = q[i].F, r = q[i].S;
        add[i] = 0;
        for (int j = 0; j < active.size(); ++j) {
            if (pos[active[j]] > l && active[j] < m[l] ||
                pos[active[j]] < l && active[j] > m[l]) {
                add[i]--;
                //cout << i << endl;
                //cout << active[j] << ' ' << pos[active[j]] << endl;
            }
            if (pos[active[j]] > r && active[j] < m[r] ||
                pos[active[j]] < r && active[j] > m[r]) {
                add[i]--;
                //cout << i << endl;
            }
        }
        if (m[l] > m[r]) {
            add[i]++;
        }
        if (m[l] > m[r]) {
            //cout << m[l] << ' ' << m[r] << endl;
            v.pb(query(l + 1, r - 1, m[l], i, -2));
            v.pb(query(l + 1, r - 1, m[r], i, 2));
        } else {
            v.pb(query(l + 1, r - 1, m[r], i, 2));
            v.pb(query(l + 1, r - 1, m[l], i, -2));
        }
        swap(m[l], m[r]);
        pos[m[l]] = l;
        pos[m[r]] = r;
        for (int j = 0; j < active.size(); ++j) {
            if (pos[active[j]] > l && active[j] < m[l] ||
                pos[active[j]] < l && active[j] > m[l]) {
                add[i]++;
            }
            if (pos[active[j]] > r && active[j] < m[r] ||
                pos[active[j]] < r && active[j] > m[r]) {
                add[i]++;
            }
        }
        if (m[l] > m[r]) {
            add[i]--;
        }
    }
   // for (int i = from; i <= to; ++i) cout << add[i] << ' ';
    //cout << endl;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    //cout << v.size() << endl;
    /*for (int i = 0; i < v.size(); ++i) {
        query q = v[i];
        cout << q.l << ' ' <<q.r << ' ' <<q.base << ' ' <<q.ind<<endl;
    }*/
    for (int i = 0; i < n; ++i) {
        if (used[i] == false) {
            set_bit(pos[i]);
            continue;
        }
        //cout << i << endl;
        while(!v.empty() && v.back().base == i) {
            query q = v.back();
         //   cout << q.l << ' ' <<q.r << ' ' <<q.base << ' ' <<q.ind << ' ' << q.mult <<endl;
          //  cout << get_sum(q.l, q.r) << endl;
            v.pop_back();
            add[q.ind] += (q.mult * get_sum(q.l, q.r));
        }
    }
}

int main()
{
   // freopen("input.txt", "r", stdin);
    cin >> n >> qnum;
    for (int i = 0; i < n; ++i) {
        m[i] = i;
    }
    for (int i = 0; i < qnum; ++i) {
        scanf("%d%d", &q[i].F, &q[i].S);
        --q[i].F, --q[i].S;
        if (q[i].F > q[i].S) {
            swap(q[i].F, q[i].S);
        }
    }
    int curq = 0;
    int sq = round(sqrt(qnum));
    //sq = 1;
    kor = round(sqrt(n)) + 1;
    while (curq < qnum) {
        solve(curq, min(qnum - 1, curq + sq));
        //solve(curq, 1);
        curq += sq + 1;
        //break;
    }
    ll cur = 0;
    for (int i = 0; i < qnum; ++i) {
        cur += add[i];
        printf("%I64d\n", cur);
    }
    return 0;
}