#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

const int maxn = 1000100;

int N, K;
int C[maxn];

vector<int> vdiv[maxn];

void init() {
    for (int i = 2; i < maxn; i++)
        if (vdiv[i].empty())
            for (int j = i; j < maxn; j += i)
                vdiv[j].push_back(i);
}

int ma[maxn];

int main() {
    init();

    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &C[i]);
        int x = C[i];
        for (int j : vdiv[x]) {
            int k = 0;
            while (C[i] % j == 0) k++, C[i] /= j;
            ma[j] = max(ma[j], k);
        }
    }

    int x = K;
    for (int i : vdiv[K]) {
        int k = 0;
        while (K % i == 0) k++, K /= i;
        if (k > ma[i]) {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
}