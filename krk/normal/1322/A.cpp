#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int n;
char S[Maxn];
int st;
vector <int> seq;
int nd[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    scanf("%s", S + 1);
    for (int i = 1; i <= n; i++)
        if (S[i] == '(') {
            st++;
            if (!seq.empty() && S[seq.back()] == ')') {
                nd[seq.back()]++; nd[i + 1]--;
                seq.pop_back();
            } else seq.push_back(i);
        } else {
            st--;
            if (!seq.empty() && S[seq.back()] == '(') seq.pop_back();
            else seq.push_back(i);
        }
    if (st != 0) { printf("-1\n"); return 0; }
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += nd[i];
        if (cur > 0) res++;
    }
    printf("%d\n", res);
    return 0;
}