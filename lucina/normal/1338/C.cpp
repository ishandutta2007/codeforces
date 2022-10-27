#include<bits/stdc++.h>
using namespace std;
int const nax = 1e6 + 10;
using ll = long long;


ll f_first (ll x) {
    ll res = 1;
    while (res * 4LL < x) res *= 4LL;
    if (res * 4 == x) res *= 4;
    ll dif = (x - res) / 3;

    return res + dif;
}

ll f_second (ll x) {


    ll res = 1;
    while (res * 4LL < x) res *= 4LL;
    if (res * 4LL == x ) res *= 4LL;

    ll dif = (x - res + 1) / 3;

    ll now = 1;

    ll tot = 0;

    x = dif;

    while (x > 0) {

        switch (x % 4) {
        case 0:
            break;
        case 1:
            tot += now * 2LL;
            break;
        case 2:
            tot += now * 3LL;
            break;
        case 3:
            tot += now;
            break;
        default: throw;
        }

        x >>= 2;
        now <<= 2;
    }

    return tot;
}

void solve () {
    ll n;
    scanf("%lld", &n);
    if (n <= 3) {
        printf("%lld\n", n);
        return;
    }

    ll x = n;
    while (x % 3 != 1) -- x;
    ll y = f_first(x);
    ++ x;
    ll z = f_second(x);
    ll mx_bit = 0;

    for (int j = 0 ; j < 61 ; ++ j) {
        if (y >> j & 1) mx_bit = j;
    }


    z ^= (2LL << mx_bit);
    if (n % 3 == 1) {
        printf("%lld\n", y);
    } else if (n % 3 == 2) {
        printf("%lld\n", z);
    } else {
        printf("%lld\n", y ^ z);
    }

}

int main () {

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
    /*
    /*while (true) {
        int x;
        scanf("%d", &x);
        print_bin(x);
        printf("\n");

    }*/

/*
    clock_t start = clock();
    int ct = 0;
    while ((clock() - start) / (double)CLOCKS_PER_SEC <= 5.0) {

        int st = 1;
        while (used[st]) ++ st;


        int j = st + 1;
        while (true && (clock() - start) / (double)CLOCKS_PER_SEC <= 5.0) {
            while (used[j]) ++ j;
            if (used[st ^ j]) {
                ++ j;
                continue;
            } else break;
        }

        used[st] = used[j] = used[st ^ j] = true;
       // printf("[%d %d %d] ", st, j, st ^ j);
        if  (ct % 4 == 1)
        printf("%d: ", j), print_bin(j), printf("\n");
        ++ ct;
    }


*/
}

/**
/*
    Good Luck
        -Lucina
*/

/**
[1 2 3]
[4 8 12] [5 10 15] [6 11 13] [7 9 14]

[16 32 48] [17 34 51] [18 35 49] [19 33 50] [20 40 60]
[21 42 63] [22 43 61] [23 41 62] [24 44 52] [25 46 55]
[26 47 53] [27 45 54] [28 36 56] [29 38 59] [30 39 57]
[31 37 58]

[64 128 192] [65 130 195] [66 131 193] [67 129 194]
[68 136 204] [69 138 207] [70 139 205] [71 137 206]
[72 140 196] [73 142 199] [74 143 197] [75 141 198]
[76 132 200] [77 134 203] [78 135 201] [79 133 202]
[80 160 240] [81 162 243] [82 163 241] [83 161 242]
[84 168 252] [85 170 255] [86 171 253] [87 169 254]
[88 172 244] [89 174 247] [90 175 245] [91 173 246]
[92 164 248] [93 166 251] [94 167 249] [95 165 250]
[96 176 208] [97 178 211] [98 179 209] [99 177 210]
[100 184 220] [101 186 223] [102 187 221] [103 185 222]
[104 188 212] [105 190 215] [106 191 213] [107 189 214]
[108 180 216] [109 182 219] [110 183 217] [111 181 218]
[112 144 224] [113 146 227] [114 147 225] [115 145 226]
[116 152 236] [117 154 239] [118 155 237] [119 153 238]
[120 156 228] [121 158 231] [122 159 229] [123 157 230]
[124 148 232] [125 150 235] [126 151 233] [127 149 234]

*/