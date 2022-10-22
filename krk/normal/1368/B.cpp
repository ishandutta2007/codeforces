#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxd = 10;
const string cf = "codeforces";

ll k;
int seq[Maxd];

bool Check()
{
    ll cur = 1;
    for (int i = 0; i < Maxd; i++)
        cur *= seq[i];
    return cur >= k;
}

int main()
{
    cin >> k;
    for (int i = 0; i < Maxd; i++)
        seq[i] = 1;
    bool ok = Check();
    while (!ok)
        for (int i = 0; i < Maxd && !ok; i++) {
            seq[i]++;
            ok = Check();
        }
    for (int i = 0; i < Maxd; i++)
        for (int j = 0; j < seq[i]; j++)
            printf("%c", cf[i]);
    printf("\n");
    return 0;
}