#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxd = 4;

ll a[Maxd];
int tk[Maxd];

void Add(int quer, int ind, ll add)
{
    tk[ind] = quer + 1;
    a[ind] += add;
    printf("%d\n", ind); fflush(stdout);
}

bool Check(int ind, ll add)
{
    a[ind] += add;
    bool ok = true, notmax = false;
    for (int i = 1; i < Maxd; i++) if (ind != i) {
        if (a[ind] == a[i]) ok = false;
        if (a[ind] < a[i]) notmax = true;
    }
    if (!ok) { a[ind] -= add; return false; }
    if (notmax) { a[ind] -= add; return true; }
    vector <llll> seq;
    for (int i = 1; i < Maxd; i++)
        seq.push_back(llll(a[i], i));
    sort(seq.begin(), seq.end());
    a[ind] -= add;
    return seq[2].first - seq[1].first != seq[1].first - seq[0].first;
}

int main()
{
    for (int i = 1; i < Maxd; i++)
        scanf("%I64d", &a[i]);
    printf("First\n"); fflush(stdout);
    for (int i = 1; ; i++) {
        vector <llll> seq;
        for (int j = 1; j < Maxd; j++)
            seq.push_back(llll(a[j], j));
        sort(seq.begin(), seq.end());
        ll add;
        if (seq[2].first - seq[1].first == seq[1].first - seq[0].first && tk[seq[2].second] == i)
            add = seq[2].first - seq[1].first;
        else add = 2ll * seq[2].first - seq[1].first - seq[0].first;
        printf("%I64d\n", add); fflush(stdout);
        int ind; scanf("%d", &ind);
        if (ind == 0) break;
        a[ind] += add; tk[ind] = i + 1;
    }
    return 0;
}