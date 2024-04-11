#include <bits/stdc++.h>
using namespace std;

typedef pair <int, char> ic;

const int Maxn = 200005;

int n;
int a[Maxn];
vector <ic> seq;

vector <ic> getLeft(int l, int r, vector <ic> give)
{
    vector <ic> res = give;
    while (l <= r) {
        if (res.empty() || res.back().first < a[l]) {
            res.push_back(ic(a[l], 'L'));
            l++;
        } else break;
    }
    return res;
}

vector <ic> getRight(int l, int r, vector <ic> give)
{
    vector <ic> res = give;
    while (l <= r) {
        if (res.empty() || res.back().first < a[r]) {
            res.push_back(ic(a[r], 'R'));
            r--;
        } else break;
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int lef = 0, rig = n - 1;
    while (lef <= rig)
        if (!seq.empty() && seq.back().first >= a[lef]) {
            seq = getRight(lef, rig, seq);
            break;
        } else if (!seq.empty() && seq.back().first >= a[rig]) {
            seq = getLeft(lef, rig, seq);
            break;
        } else if (a[lef] < a[rig]) {
            seq.push_back(ic(a[lef], 'L'));
            lef++;
        } else if (a[lef] > a[rig]) {
            seq.push_back(ic(a[rig], 'R'));
            rig--;
        } else {
            vector <ic> res1 = getLeft(lef, rig, seq);
            vector <ic> res2 = getRight(lef, rig, seq);
            if (res1.size() >= res2.size()) seq = res1;
            else seq = res2;
            break;
        }
    printf("%d\n", int(seq.size()));
    for (int i = 0; i < seq.size(); i++)
        printf("%c", seq[i].second);
    printf("\n");
    return 0;
}