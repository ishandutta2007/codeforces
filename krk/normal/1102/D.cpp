#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int n;
string s;
deque <int> V[3];

int main()
{
    scanf("%d", &n);
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        V[s[i] - '0'].push_back(i);
    int nd = int(s.length()) / 3;
    while (V[0].size() < nd) {
        int best = s.length();
        if (V[1].size() > nd) best = min(V[1][0], best);
        if (V[2].size() > nd) best = min(V[2][0], best);
        V[0].push_back(best);
        if (V[1].size() > nd && V[1][0] == best) V[1].pop_front();
        else V[2].pop_front();
        s[best] = '0';
    }
    while (V[2].size() < nd) {
        int best = 0;
        if (V[0].size() > nd) best = max(V[0].back(), best);
        if (V[1].size() > nd) best = max(V[1].back(), best);
        V[2].push_back(best);
        if (V[0].size() > nd && V[0].back() == best) V[0].pop_back();
        else V[1].pop_back();
        s[best] = '2';
    }
    while (V[1].size() < nd)
        if (V[2].size() > nd) {
            V[1].push_back(V[2][0]);
            s[V[2][0]] = '1';
            V[2].pop_front();
        } else {
            V[1].push_back(V[0].back());
            s[V[0].back()] = '1';
            V[0].pop_back();
        }
    cout << s << endl;
    return 0;
}