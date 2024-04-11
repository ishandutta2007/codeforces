#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

vector <int> inds[Maxn], BIT[Maxn];
int n, k;
int X[Maxn], R[Maxn], Q[Maxn];
int inQ[Maxn];
vector <int> unQ;
ll res;

void Add(vector <int> &BIT, int x, int val)
{
    x++;
    for (int i = x; i > 0; i -= i & -i)
        BIT[i] += val;
}

int Get(const vector <int> &BIT, int x)
{
    x++;
    int res = 0;
    for (int i = x; i < BIT.size(); i += i & -i)
        res += BIT[i];
    return res;
}

bool Less(const int &a, const int &b)
{
    return R[a] > R[b];
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &X[i], &R[i], &Q[i]);
        unQ.push_back(Q[i]);
    }
    sort(unQ.begin(), unQ.end()); unQ.erase(unique(unQ.begin(), unQ.end()), unQ.end());
    vector <int> seq;
    for (int i = 0; i < n; i++) {
        inQ[i] = lower_bound(unQ.begin(), unQ.end(), Q[i]) - unQ.begin();
        inds[inQ[i]].push_back(X[i]);
        seq.push_back(i);
    }
    for (int i = 0; i < unQ.size(); i++) {
        sort(inds[i].begin(), inds[i].end());
        inds[i].erase(unique(inds[i].begin(), inds[i].end()), inds[i].end());
        BIT[i].resize(inds[i].size() + 1, 0);
    }
    sort(seq.begin(), seq.end(), Less);
    for (int i = 0; i < n; i++) {
        int v = seq[i];
        int lef = lower_bound(unQ.begin(), unQ.end(), Q[v] - k) - unQ.begin();
        int rig = upper_bound(unQ.begin(), unQ.end(), Q[v] + k) - unQ.begin();
        for (int j = lef; j < rig; j++) {
            int l = lower_bound(inds[j].begin(), inds[j].end(), X[v] - R[v]) - inds[j].begin();
            int r = upper_bound(inds[j].begin(), inds[j].end(), X[v] + R[v]) - inds[j].begin();
            if (l < r) res += Get(BIT[j], l) - Get(BIT[j], r);
        }
        int myind = lower_bound(inds[inQ[v]].begin(), inds[inQ[v]].end(), X[v]) - inds[inQ[v]].begin();
        Add(BIT[inQ[v]], myind, 1);
    }
    cout << res << endl;
    return 0;
}