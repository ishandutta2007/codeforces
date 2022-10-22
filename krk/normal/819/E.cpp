#include <bits/stdc++.h>
using namespace std;

int n;
vector <vector <int> > res;

void Solve(vector <int> &seq)
{
    if (seq.size() == 3) {
        res.push_back({seq[0], seq[1], seq[2]});
        res.push_back({seq[0], seq[1], seq[2]});
        return;
    }
    if (seq.size() == 4) {
        res.push_back({seq[0], seq[1], seq[2]});
        res.push_back({seq[0], seq[1], seq[3]});
        res.push_back({seq[2], seq[3], seq[0]});
        res.push_back({seq[2], seq[3], seq[1]});
        return;
    }
    int a = seq.back(); seq.pop_back();
    int b = seq.back(); seq.pop_back();
    for (int i = 0; i + 1 < seq.size(); i++)
        res.push_back({a, seq[i], b, seq[i + 1]});
    res.push_back({a, b, seq[0]});
    res.push_back({a, b, seq.back()});
    Solve(seq);
}

int main()
{
    scanf("%d", &n);
    vector <int> seq;
    for (int i = 1; i <= n; i++)
        seq.push_back(i);
    Solve(seq);
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++) {
        printf("%d", int(res[i].size()));
        for (int j = 0; j < res[i].size(); j++)
            printf(" %d", res[i][j]);
        printf("\n");
    }
    return 0;
}