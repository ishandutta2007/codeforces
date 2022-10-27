#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, k;
int a[nax];
int c[nax];
int to[nax];
int ct[nax];

vector <int> cramp[nax];
vector <int> wait[nax];


int main () {
    scanf("%d %d", &n, &k);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
        ++ ct[a[i]];
    }

    for (int i = 1 ; i <= k ; ++ i)
        scanf("%d", c + i);



    int cur = k;

    for (int i = k ; i >= 1 ; -- i ) {
        int j = i;
        while (j > 0 && c[i] == c[j]) -- j;

        for (int v = i ; v > j ; -- v) to[c[i]] = j;
        i = j + 1;
    }


    vector <int> q;
    int ptr = 0, ans = 0;
    for (int i = k ; i >= 1 ; -- i) {

        for (int j : wait[i]) {
            q.push_back(j);
        }
        if (!ct[i]) continue;

        while (true) {
            if (ptr >= (int)q.size()) q.push_back(++ ans);
            int can_put = c[i] - (int)cramp[q[ptr]].size();

            if (can_put >= ct[i]) {

                for (int j = 0 ; j < ct[i] ; ++ j)
                    cramp[q[ptr]].push_back(i);

                if (cramp[q[ptr]].size() == c[i])
                    wait[to[c[i]]].push_back(q[ptr]), ptr ++;
                break;
            } else {
                ct[i] -= can_put;

                for (int j = 0 ; j < can_put ; ++ j)
                    cramp[q[ptr]].push_back(i);
                wait[to[c[i]]].push_back(q[ptr]), ptr ++;
            }
        }

    }

    printf("%d\n", ans);

    for (int i = 1 ; i <= ans ; ++ i) {
        printf("%d ", (int)cramp[i].size());
        for (int j : cramp[i])
            printf("%d ", j);
        printf("\n");
    }
}