#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 200005;

int n;
int a[Maxn];
int freq[Maxn];
vector <iii> V;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        freq[a[i]]++;
    }
    int mn = 0;
    for (int i = 1; i < Maxn; i++)
        if (freq[i] > freq[mn]) mn = i;
    for (int i = 2; i <= n; i++) if (a[i] == mn) {
        for (int j = i - 1; j > 0 && a[j] != mn; j--) {
            if (a[j] > mn) V.push_back(iii(ii(j, j + 1), 2));
            else V.push_back(iii(ii(j, j + 1), 1));
            a[j] = mn;
        }
    }
    int lst = n;
    while (a[lst] != mn) lst--;
    for (int j = lst + 1; j <= n; j++) if (a[j] != mn)
        if (a[j] > mn) V.push_back(iii(ii(j, j - 1), 2));
        else V.push_back(iii(ii(j, j - 1), 1));
    printf("%d\n", int(V.size()));
    for (int i = 0; i < V.size(); i++)
        printf("%d %d %d\n", V[i].second, V[i].first.first, V[i].first.second);
    return 0;
}