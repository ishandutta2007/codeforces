#include <bits/stdc++.h>
using namespace std;

const int Maxf = 10;

int pos[Maxf];
int V[Maxf];
int my[Maxf];

void Read()
{
    int k; scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.length(); j++)
            my[s[j] - '0'] = i;
    }
}

void Move(int x) { printf(" %d", x); pos[x]++; }

void Move(vector <int> V)
{
    printf("next");
    for (int i = 0; i < V.size(); i++)
        Move(V[i]);
    printf("\n"); fflush(stdout);
    Read();
}

void Move(int l, int r)
{
    printf("next");
    for (int i = 0; i < Maxf; i++)
        if (l <= i && i <= r)
            Move(i);
    printf("\n"); fflush(stdout);
    Read();
}

int main()
{
    V[0] = 1;
    for (int i = 1; i < Maxf; i++)
        V[i] = 2 * (V[i - 1] + 1) + 1;
    Move(0, Maxf - 1);
    int nxt = 1;
    for (int i = 2; ; i++) {
        Move(nxt, Maxf - 1);
        bool sam = false;
        int cycle;
        for (int j = 0; j < nxt; j++)
            if (my[j] == my[nxt]) { sam = true; cycle = i - V[j]; break; }
        if (sam) {
            for (int z = 1; z < cycle; z++) {
                int cur = (1 + z) % cycle;
                vector <int> tmp;
                for (int j = 0; j < Maxf; j++) if (pos[j] % cycle == cur) {
                    V[j]++;
                    tmp.push_back(j);
                }
                if (!tmp.empty()) Move(tmp);
            }
            for (int j = 2; my[0] != my[nxt - 1]; j++)
                Move(0, Maxf - 1);
            printf("done\n"); fflush(stdout);
            return 0;
        }
        if (i == V[nxt]) nxt++;
    }
    printf("done\n"); fflush(stdout);
    return 0;
}