#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef vector<int> vi;
typedef pair<int64,char> P;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int64 tonum(string s){
    int64 a = 0;
    for (auto c : s)
        a = a * 10 + c - '0';
    return a;
}

vector<P> read(int n){
    vector<P> A;
    for (int i = 0; i < n; ++i){
        string s; cin >> s;
        char c = s.back(); s.pop_back(); s.pop_back();
        int64 v = tonum(s);

        if (!A.empty() && A.back().second == c)
            A.back().first += v;
        else
            A.push_back({v, c});
    }

    return A;
}

vector<int> prefix_function(vector<P> s)
{
    int n = (int)s.size();
    vector<int> pi(n + 1);

    for (int i = 0, j = pi[0] = -1; i < n; pi[++i] = ++j)
        while (j >= 0 && s[i] != s[j]) j = pi[j];

    return pi;
}

vector<int> kmp(vector<P> s, vector<P> p)
{
    auto pi = prefix_function(p);
    int n = (int)s.size(), m = (int)p.size();

    vector<int> ans;

    for (int i = 0, j = 0; i < n; ++i)
    {
        while (j >= 0 && s[i] != p[j])
            j = pi[j];

        if (++j == m)
            ans.push_back(i - m + 1);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<P> A = read(n), B = read(m);

    int64 answer = 0;

    if (B.size() == 1){
        P c = B[0];
        for (auto a : A){
            if (a.second == c.second)
                answer += max(0LL, a.first - c.first + 1);
        }
    }
    else if (B.size() == 2){
        for (int i = 0; i + 1 < (int)A.size(); ++i){
            if (A[i].second == B[0].second && A[i + 1].second == B[1].second)
                answer += B[0].first <= A[i].first && B[1].first <= A[i + 1].first;
        }
    }
    else{
        vector<P> C(B.begin() + 1, B.begin() + (int)B.size() - 1);
        int sz = (int)B.size() - 2;

        vector<int> pos = kmp(A, C);
        for (auto p : pos){
            if (p > 0 && p + sz < (int)A.size())
                if (A[p - 1].second == B[0].second && A[p + sz].second == B.back().second)
                    answer += B[0].first <= A[p - 1].first && B.back().first <= A[p + sz].first;
        }
    }

    cout << answer << endl;

    return 0;
}