#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 100005;

int n, t;
string s;
int pnt, boys, cur;
int delt[Maxn];
int glob;
int cnt[Maxn];

void Add(int l, int r, int val)
{
    if (r < pnt) return;
    if (l <= pnt) cur += val;
    else delt[l] += val;
    delt[r + 1] -= val;
}

int main()
{
    cin >> n >> t;
    cin >> s;
    vector <iii> seq;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'B') {
            iii p = iii(boys - glob, ii(boys, boys));
            boys++;
            while (!seq.empty() && seq.back().first < p.first) {
                Add(seq.back().second.first, seq.back().second.second, p.first - seq.back().first);
                p.second.first = seq.back().second.first; seq.pop_back();
            }
            seq.push_back(p);
        } else {
            glob++;
            Add(0, boys - 1, 1);
            while (pnt < boys && cur > t)
                cur += delt[++pnt];
            cnt[pnt]++;
        }
    }
    while (cnt[0]--) printf("G");
    for (int i = 1; i <= boys; i++) {
        printf("B");
        while (cnt[i]--) printf("G");
    }
    printf("\n");
    return 0;
}