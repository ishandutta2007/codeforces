#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxd = 3;
const int Maxn = 200005;

string S[Maxd];
int Z[Maxn];
int save[Maxd][Maxd];
bool cangetin[Maxd][Maxd];
int perm[Maxd];
int best;

int getSave(int a, int b)
{
    string s = S[b] + " " + S[a];
    fill(Z, Z + Maxn, 0);
    int l = 0, r = 0;
    for (int i = 1; i < s.length(); i++) {
        if (i <= r) Z[i] = min(Z[i - l], r - i + 1);
        while (i + Z[i] < s.length() && s[Z[i]] == s[i + Z[i]]) Z[i]++;
        if (Z[i]) { l = i; r = i + Z[i] - 1; }
    }
    for (int i = S[b].length() + 1; i < s.length(); i++) {
        if (Z[i] == S[b].length()) cangetin[a][b] = true;
        if (i + Z[i] == s.length()) return Z[i];
    }
    return 0;
}

int main()
{
    for (int i = 0; i < Maxd; i++) getline(cin, S[i]);
    for (int i = 0; i < Maxd; i++)
        for (int j = 0; j < Maxd; j++) if (i != j)
            save[i][j] = getSave(i, j);
    for (int i = 0; i < Maxd; i++) perm[i] = i;
    do {
        best = max(best, save[perm[0]][perm[1]] + save[perm[1]][perm[2]]);
        if (cangetin[perm[0]][perm[1]]) {
            best = max(best, int(S[perm[1]].length()) + save[perm[2]][perm[0]]);
            best = max(best, int(S[perm[1]].length()) + save[perm[0]][perm[2]]);
            if (cangetin[perm[0]][perm[2]])
                best = max(best, int(S[perm[1]].length()) + int(S[perm[2]].length()));
        }
    } while (next_permutation(perm, perm + Maxd));
    cout << S[0].length() + S[1].length() + S[2].length() - best << endl;
    return 0;
}