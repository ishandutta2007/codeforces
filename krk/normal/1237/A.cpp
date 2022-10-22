#include <bits/stdc++.h>
using namespace std;

const int Maxn = 20005;

int n;
int a[Maxn];
int st = 0;
vector <int> seq;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0) a[i] /= 2;
        else {
            seq.push_back(i);
            if (a[i] < 0) a[i] = -((-a[i]) / 2) - 1;
            else a[i] /= 2;
        }
        st += a[i];
    }
    for (int i = 0; i < seq.size() && st < 0; i++) {
        a[seq[i]]++; st++;
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}