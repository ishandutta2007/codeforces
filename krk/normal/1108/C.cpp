#include <bits/stdc++.h>
using namespace std;

const string lets = "RGB";

string s, r;
int res = 1000000000;
vector <int> best;

void Color(const vector <int> &V)
{
    for (int i = 0; i < r.length(); i++)
        r[i] = lets[V[i % 3]];
}

int main()
{
    int n; scanf("%d", &n);
    cin >> s;
    r.resize(s.length());
    vector <int> V;
    for (int i = 0; i < lets.size(); i++)
        V.push_back(i);
    do {
        Color(V);
        int difs = 0;
        for (int i = 0; i < r.length(); i++)
            difs += r[i] != s[i];
        if (difs < res) {
            res = difs;
            best = V;
        }
    } while (next_permutation(V.begin(), V.end()));
    Color(best);
    int difs = 0;
    for (int i = 0; i < r.length(); i++)
        difs += r[i] != s[i];
    printf("%d\n", difs);
    printf("%s\n", r.c_str());
    return 0;
}