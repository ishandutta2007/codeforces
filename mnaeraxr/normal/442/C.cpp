#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 500010;

int V[maxn], L[maxn], R[maxn], n;

int val(int p){
    return min(V[L[p]], V[R[p]]);
}

void remove(int p){
    if (L[p] != -1) R[ L[p] ] = R[p];
    if (R[p] !=  n) L[ R[p] ] = L[p];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i){
        cin >> V[i];
        L[i] = i - 1, R[i] = i + 1;
    }

    set<pii> S;

    for (int i = 0; i < n; ++i)
        S.insert({V[i], i});

    int64 answer = 0;

    while (S.size() > 2){
        auto best = *S.begin();

        int pos = best.second;

        if (L[pos] == -1 || R[pos] == n)
            answer += V[pos];
        else
            answer += val(pos);

        S.erase(best);

        remove(pos);
    }

    cout << answer << endl;

    return 0;
}