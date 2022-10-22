#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];
bool rem[Maxn];
vector <int> neg, zer, pos;

void Remove()
{
    int st = 1;
    while (st <= n && !rem[st]) st++;
    for (int i = st + 1; i <= n; i++) if (rem[i])
        printf("1 %d %d\n", i, st);
    if (st <= n) printf("2 %d\n", st);
    st = 1;
    while (rem[st]) st++;
    for (int i = st + 1; i <= n; i++) if (!rem[i])
        printf("1 %d %d\n", i, st);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0) neg.push_back(i);
        else if (a[i] == 0) zer.push_back(i);
        else pos.push_back(i);
    }
    if (int(neg.size()) % 2) {
        int ind = 0;
        for (int i = 0; i < neg.size(); i++)
            if (a[neg[i]] > a[neg[ind]]) ind = i;
        rem[neg[ind]] = true;
    }
    for (int i = 0; i < zer.size(); i++)
        rem[zer[i]] = true;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += rem[i];
    if (cnt >= n) rem[zer.back()] = false;
    Remove();
    return 0;
}