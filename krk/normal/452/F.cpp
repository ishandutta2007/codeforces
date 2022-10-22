#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int n;
vector <int> P;
int inP[Maxn];
int lef, rig;

vector <int> Fix(vector <int> &P)
{
    for (int i = 0; i < P.size(); i++)
        P[i] = (P[i] + 1) / 2;
    return P;
}

bool Add(int x, vector <int> &my, vector <int> &oth)
{
    for (int i = 0; i < my.size(); i++) {
        int el = (x + my[i]) / 2;
        if (lef <= inP[el] && inP[el] <= rig) return true;
    }
    for (int i = 0; i < oth.size(); i++) {
        int el = 2 * x - oth[i];
        if (1 <= el && el <= n &&
            lef <= inP[el] && inP[el] <= rig) return true;
    }
    return false;
}

bool hasPairCorrect(const vector <int> &P)
{
    for (int i = 0; i < P.size(); i++)
        for (int j = i + 1; j < P.size(); j++)
            for (int k = j + 1; k < P.size(); k++)
                if (P[i] + P[k] == 2 * P[j]) return true;
    return false;
}

bool hasPair(const vector <int> &P)
{
    if (P.size() <= 2) return false;
    n = P.size();
    for (int i = 0; i < P.size(); i++) {
        inP[P[i]] = i;
        assert(1 <= P[i] && P[i] <= n);
    }
    lef = 0, rig = int(P.size()) - 1;
    vector <int> Le, Re;
    vector <int> Lo, Ro;
    bool flag = true;
    while (lef < rig) {
        if (flag) {
            int ind = lef++;
            if (P[ind] % 2) {
                Lo.push_back(P[ind]);
                if (Add(P[ind], Ro, Le)) return true;
            } else {
                Le.push_back(P[ind]);
                if (Add(P[ind], Re, Lo)) return true;
            }
        } else {
            int ind = rig--;
            if (P[ind] % 2) {
                Ro.push_back(P[ind]);
                if (Add(P[ind], Lo, Re)) return true;
            } else {
                Re.push_back(P[ind]);
                if (Add(P[ind], Le, Ro)) return true;
            }
        }
        flag = !flag;
    }
    if (P[lef] % 2) Lo.push_back(P[lef]);
    else Le.push_back(P[lef]);
    reverse(Ro.begin(), Ro.end());
    reverse(Re.begin(), Re.end());
    Lo.insert(Lo.end(), Ro.begin(), Ro.end());
    Le.insert(Le.end(), Re.begin(), Re.end());
    if (hasPair(Fix(Lo))) return true;
    if (hasPair(Fix(Le))) return true;
    return false;
}

int main()
{
    scanf("%d", &n);
    P.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &P[i]);
    printf("%s\n", hasPair(P)? "YES": "NO");
    return 0;
}