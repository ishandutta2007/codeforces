#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int n;
int per1[N], per2[N], where1[N], where2[N];

vector< pair<int, int> > ans;
int cost;

void mySwap(int a, int b) {
    swap(per1[a], per1[b]);
    where1[per1[a]] = a;
    where1[per1[b]] = b;
    ans.push_back(make_pair(a, b));
    cost += b - a;
}

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &per1[i]);
        where1[per1[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &per2[i]);
        where2[per2[i]] = i;
    }

    for (int i = n; i >= 1; i--) {
        int w = i;
        while (where1[per1[w]] < where2[per1[w]]) {
            int j = where1[per1[w]] + 1;
            while (j <= n) {
                if (j == where2[per1[w]]) {
                    mySwap(w, j);
                    break;
                } else if (where2[per1[j]] < j) {
                    mySwap(w, j);
                    w = j;
                } else {
                    j++;
                }
            }
        }
    }

    printf("%d\n%d\n", cost, (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }

    return 0;
}