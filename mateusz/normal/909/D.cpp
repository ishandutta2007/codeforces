#include <bits/stdc++.h>

using namespace std;

const int N = 1000006, INF = 1e9;

int n;
char tab[N];

int pref[N], suf[N];
int rep[N], leftRep[N];
bool done[N];

int find(int w) {
    return w == rep[w] ? w : (rep[w] = find(rep[w]));
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    rep[a] = b;
    leftRep[b] = min(leftRep[b], leftRep[a]);
}

int main() {
    
    scanf(" %s", &tab[1]);
    n = strlen(tab + 1);
    queue<int> Q;
    for (int i = 1; i <= n + 1; i++) rep[i] = leftRep[i] = i;
    for (int i = 1; i <= n; i++) {
        if ((i < n && tab[i] != tab[i + 1]) || (i > 1 && tab[i] != tab[i - 1])) {
            done[i] = true;
            Q.push(i);
        }
    }
    
    int ans = 0;
    while (!Q.empty()) {
        vector<int> tmp;
        bool good = false;
        while (!Q.empty()) {
            int w = Q.front();
            Q.pop();
            good = true;
            tmp.push_back(w);
        }
        if (good) ans++;
//         cerr << "elo\n";
        for (int x : tmp) {
//             cerr << x << " ";
            Union(x, find(x) + 1);
        }
//         cerr << endl;
//         cerr << "tutu\n";
        for (int x : tmp) {
//             cerr << x << " " << find(x) << " " << leftRep[find(x)] << endl;
            int f = find(x);
            if (leftRep[f] - 1 >= 1 && find(x) <= n && tab[leftRep[f] - 1] != tab[find(x)]) {
                if (!done[leftRep[f] - 1]) {
                    done[leftRep[f] - 1] = true;
                    Q.push(leftRep[f] - 1);
                }
                if (!done[find(x)]) {
                    done[find(x)] = true;
                    Q.push(find(x));
                }
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}