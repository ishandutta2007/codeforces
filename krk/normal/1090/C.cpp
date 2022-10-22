#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 100005;

int n, m;
set <int> S[Maxn];
int need[Maxn];
int seq[Maxn];
vector <iii> res;
int tot;

bool Less(const int &a, const int &b)
{
    return S[a].size() < S[b].size();
}

void Move(int a, int b, int c)
{
    res.push_back(iii(ii(a, b), c));
    S[a].erase(c);
    S[b].insert(c);
}

void Move(int a, int b)
{
    set <int>::iterator itl = S[b].begin(), itr = S[a].begin();
    vector <int> add;
    while ((itl != S[b].end() || itr != S[a].end()) &&
           S[b].size() + add.size() < need[b] &&
           S[a].size() > need[a] + add.size())
        if (itl != S[b].end() && (itr == S[a].end() || *itl < *itr))
            itl++;
        else if (itr != S[a].end() && (itl == S[b].end() || *itr < *itl)) {
            add.push_back(*itr); itr++;
        } else { itl++; itr++; }
    for (int i = 0; i < add.size(); i++)
        Move(a, b, add[i]);
}

int main()
{
    scanf("%d %d", &n, &m);
    tot = 0;
    for (int i = 1; i <= n; i++) {
        seq[i - 1] = i;
        int s; scanf("%d", &s);
        for (int j = 0; j < s; j++) {
            int x; scanf("%d", &x);
            S[i].insert(x);
        }
        tot += s;
    }
    sort(seq, seq + n, Less);
    for (int i = 0; i < n; i++)
        need[seq[i]] = tot / n;
    for (int i = 1; i <= tot % n; i++)
        need[seq[n - i]]++;
    int l = 0, r = n - 1;
    while (l < r)
        if (S[seq[r]].size() == need[seq[r]]) r--;
        else if (S[seq[l]].size() == need[seq[l]]) l++;
        else Move(seq[r], seq[l]);
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d %d\n", res[i].first.first, res[i].first.second, res[i].second);
    return 0;
}