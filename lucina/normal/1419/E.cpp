#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

vector <int> get_grey_code(int x) {
    ///why I wrote it recursively let's see performance
    ///guess : not much different or not at all
    vector <int> cur{0, 1};
    for (int i = 1 ; i < x ; ++ i) {
        for (int j = int(cur.size()) - 1 ;j >= 0 ; -- j) {
            cur.push_back(cur[j] * 2 + 1);
            cur[j] <<= 1;
        }
    }
    return cur;
}


vector < pair <int, int>> factorize(int64_t n) {
    vector < pair <int, int>> res;
    for (int64_t j = 2 ; j * j <= n ; ++ j) {
        if (n % j == 0) {
            int ct = 0;
            do {
                n /= j;
                ct += 1;
            } while (n % j == 0);
            res.emplace_back(j, ct);
        }
    }
    if (n != 1) res.emplace_back(n, 1);
    return res;
}

void print(vector <int> masks, vector <int> primes, int n) {
    for (int mask : masks) {
        int64_t foo = 1;
        for (int j = 0 ; j < n ; ++ j)
            if (mask >> j & 1) foo *= primes[j];
        cout << foo << ' ';
    }
    cout << '\n';
}
const vector <int> mask_for_two = {3, 1, 2};

vector <int> fix(vector <int> codes, int n) {
    int tar = (1 << n) - 1;
    int pos = find(codes.begin(), codes.end(), tar) - codes.begin();
    vector <int> foo;
    for (int i = pos ; i < codes.size() ; ++ i)
        foo.push_back(codes[i]);
    for (int i = 0 ; i < pos ; ++ i)
        foo.push_back(codes[i]);
    return foo;
}

int rev_mask(int mask, int n) {
    int foo = 0;
    for (int j = 0 ; j < n ; ++ j) {
        if (!(mask >> j & 1)) foo |= (1 << j);
    }
    return foo;
}

void solve_one(vector <pair <int, int>> factor) {
    vector <int> real_fac;
    for (auto &it : factor) real_fac.push_back(it.first);
    int n = factor.size();
    if (n == 2) {
        print(mask_for_two, real_fac, 2);
        cout << 1 << '\n';
        return;
    }
    vector <int> grey_code = get_grey_code(n - 1);
    grey_code = fix(grey_code, n - 1);
    vector <int> cop = grey_code;
    cop.erase(cop.begin());
    for (int &i : cop) i = rev_mask(i, n - 1);
    for (int &code : grey_code) {
        code |= (1 << (n - 1));
    }
    for (int &i : cop) grey_code.push_back(i);
    print(grey_code, real_fac, n);
    cout << "0\n";
}

void solve() {
    int64_t n;
    cin >> n;
    vector < pair <int, int>> factor = factorize(n);
    bool is_all_one = true;
    if (factor.size() == 1) {
        int foo = factor[0].first;
        for (int j = 0 ; j < factor[0].second ; ++ j) {
            cout << foo << ' ';
            foo *= factor[0].first;
        }
        cout << '\n';
        cout << "0\n";
        return ;
    }
    for (auto &it : factor) {
        is_all_one &= (it.second == 1);
    }
    if (is_all_one) return solve_one(factor);

    map <int, vector <int>> keep;

    auto get_mask = [&](int foo)->int {
        int msk = 0;
        for (int j = 0 ; j < int(factor.size()) ; ++ j)
            if (foo % factor[j].first == 0) msk |= (1 << j);
        return msk;
    };

    for (int64_t j = 2 ; j * j <= n ; ++ j) {
        if (n % j == 0) {
            int x = j;
            int msk = get_mask(x);
            keep[msk].push_back(x);
            if (j * j != n) {
                x = n / j;
                msk = get_mask(x);
                keep[msk].push_back(x);
            }
        }
    }
    keep[get_mask(n)].push_back(int(n));

    vector <int> mask = get_grey_code(factor.size());
    mask.erase(mask.begin());
    n = factor.size();
    cout << keep[(1 << n) - 1].back() << ' ';
    keep[(1 << n) - 1].pop_back();
    for (int msk : mask) {
        for (int j : keep[msk]) cout << j << ' ';
    }
    cout << '\n';
    cout << "0\n";
}

int main() {
   // cin.tie(0)->sync_with_stdio(false);
    /**
        Info:
            If one number has one prime with degree greater than 1.
            Just generate grey code.
            Notice that there is greater than 1 masks that is all "one".
            after erasing 0, just insert that mask at position of zero
            and everything will fix.

        Q: What if the number is plainly just composition of prime?
        A: I believe that there must be proper sequences
        expect for number of primes = 2.
        Q: Belief is not enough. How to construct?
        A: ???
            1111 -> grey code generatring
            111 110 100 101 001 000 010 011
            001 001 001 010 110 111 101 100
        This works because first and last position has at least one differ bit.
        Its not-wise product should have one prime in common.
        This is exception just for two.
    */

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }

}