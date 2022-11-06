#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

pair<int, int> tab[5];

int check() {
    int ret = 0;

    if (tab[2].first == tab[3].first && abs(tab[3].second - tab[1].second) < abs(tab[2].second - tab[1].second))
        swap(tab[2], tab[3]);

    if (tab[2].second != tab[1].second) {
        ret++;
    }
    if (tab[3].first != tab[1].first) {
        ret++;
    }
    if (tab[3].second != tab[2].second && !(tab[1].first == tab[3].first)) {
        ret++;
    }

    return ret;
}

int main() {

    scanf("%d %d %d %d %d %d", &tab[1].first, &tab[1].second, &tab[2].first, &tab[2].second, &tab[3].first, &tab[3].second);

    sort(tab + 1, tab + 1 + 3);

    int ans1 = check();

    for (int i = 1; i <= 3; i++) {
        tab[i].first *= -1;
        tab[i].second *= -1;
    }
    sort(tab + 1, tab + 1 + 3);
    ans1 = min(ans1, check());

    for (int i = 1; i <= 3; i++) {
        swap(tab[i].first, tab[i].second);
    }

    sort(tab + 1, tab + 1 + 3);

    int ans2 = check();

    for (int i = 1; i <= 3; i++) {
        tab[i].first *= -1;
        tab[i].second *= -1;
    }
    sort(tab + 1, tab + 1 + 3);

    ans1 = min(ans1, check());
//     cerr << ans1 << " " << ans2 << endl;
    printf("%d\n", min(ans1, ans2));
    return 0;
}