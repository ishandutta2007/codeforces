#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, k;
int a[Maxn];
vector <ii> seq;
set <int> S;
char res[Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        seq.push_back(ii(a[i], i));
        S.insert(i);
    }
    char fir = '1', sec = '2';
    sort(seq.rbegin(), seq.rend());
    int pnt = 0;
    while (pnt < seq.size()) {
        int ind = seq[pnt].second;
        set <int>::iterator it = S.find(ind);
        set <int>::iterator it2 = it; it2++;
        for (int i = 0; i < k && it2 != S.end(); i++) {
            res[*it2] = fir; S.erase(it2++);
        }
        it2 = it;
        for (int i = 0; i < k && it2 != S.begin(); i++) {
            it2--;
            res[*it2] = fir; S.erase(it2++);
        }
        res[*it] = fir; S.erase(it);
        swap(fir, sec);
        while (pnt < seq.size() && S.find(seq[pnt].second) == S.end()) pnt++;
    }
    res[n + 1] = '\0';
    printf("%s\n", res + 1);
    return 0;
}