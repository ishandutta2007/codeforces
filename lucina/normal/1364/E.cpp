#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long ;


int n;
int hidden[1 << 14];
int zbit[15];
int num_bit;
int Q = 4269;

map < pair <int, int>, int> memo;

int ask (int i, int j) {
    -- Q;
    if (i > j) swap(i, j);
    assert(i != j);
    if (memo.count(make_pair(i, j))) return memo[make_pair(i, j)];
    printf("? %d %d\n", i + 1, j + 1);
    fflush(stdout);
    #ifdef LOCAL
        return hidden[i] | hidden[j];
    #else
        int v;
        scanf("%d", &v);
        if (v == -1) {
            throw;
        }
        return memo[make_pair(i, j)] = v;
    #endif // LOCAL
}

int get_rand() {
    return rand() % n;
}

bool ask_random_pair() {
    int i = get_rand(), j = get_rand();
    if (i == j) return false;
    int f = ask(i, j);

    for (int j = 0 ; j <= num_bit ; ++ j) {
        if (!(f >> j & 1)) {
            zbit[j] = i;
        }
    }

    for (int j = 0 ; j <= num_bit ; ++ j) {
        if (zbit[j] == -1) return false;
    }
    return true;
}

void get_zbit () {
    memset(zbit, -1, sizeof(zbit));
    while (!ask_random_pair());
}

int get_val (int idx) {
    int res = (1 << num_bit + 1) - 1;
    for (int j = 0 ; j <= num_bit ; ++ j) {
        if (zbit[j] != idx)
            res &= ask(zbit[j], idx);
    }

    for (int j = 0 ; j <= num_bit ; ++ j) {
        if (zbit[j] == idx) {
            if (res >> j & 1) res ^= 1 << j;
        }
    }
    return res;
}

int a[1 << 14];

int main () {
    srand(ull(new char()));

    #ifdef LOCAL
        n = 10;
        iota(hidden, hidden + n, 0);
        random_shuffle(hidden, hidden + n);
        printf("%d\n", n);
        for (int i = 0 ; i < n; ++ i)
            printf("%d ", hidden[i]);
        printf("\n");
    #else
        scanf("%d", &n);
    #endif // LOCAL

    for (int j = 0 ; (1 << j) < n ; ++ j) {
        if ((n - 1) >> j & 1) num_bit = j;
    }

    get_zbit();

    int idx = 0;
    int cur = get_val(idx);

    #ifdef LOCAL
        printf("num_bit %d\n", num_bit);
        for (int i = 0 ; i <= num_bit ; ++ i) {
            printf("%d ", zbit[i]);
        }
        printf("\n");
    #endif // LOCAL

    static int rand_ind[1 << 14];
    iota(rand_ind + 1, rand_ind + n, 1);
    random_shuffle(rand_ind + 1, rand_ind + n);

    for (int i = 1 ; i < n ; ++ i) {
        if (cur == 0) break;
        int get = ask(idx, rand_ind[i]);
        if ((cur & get) != get) continue;
        idx = rand_ind[i];
        cur = get_val(idx);
    }

   for (int i = 0 ; i < n ; ++ i) {
        if (i == idx) {
            a[i] = 0;
        } else a[i] = ask(i, idx);
   }

   printf("! ");
   for (int i = 0 ; i < n ; ++ i)
        printf("%d ", a[i]);
   printf("\n");
   fflush(stdout);


    assert(Q >= 0);
}