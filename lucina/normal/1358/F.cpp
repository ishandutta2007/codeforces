#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
const int LIM = 2e5;
const int BOUND = 3e6; /// array length greater than 3 cannot apply more than this
using ll = long long;
const ll INF = 1e18 + 7;
int n;

vector <ll> my_reverse(vector <ll> a) {
    reverse(a.begin(), a.end());
    return a;
}

vector <ll> to_prefix_sum (vector <ll> a) {
    for (int i = 1 ; i < int(a.size()) ; ++ i)
        a[i] += a[i - 1];
    return a;
}

vector <ll> restore (vector <ll> a) {
    for (int i = int(a.size()) - 1 ; i > 0 ; -- i)
        a[i] -= a[i - 1];
    return a;
}

bool is_equal (vector <ll> a, vector <ll> b) {
    return a == b || my_reverse(a) == b;
}

void bad_result () {
    puts("IMPOSSIBLE");
    exit(0);
}

string naive (vector <ll> a, vector <ll> b) {
    string ans;

    int iteration = 0;

    while (true) {
        if (iteration > BOUND) {
            bad_result();
        }
        if (a == b) break;
        if (a == my_reverse(b)) {
            ans += 'R';
            break;
        }

        if (is_sorted(b.begin(), b.end())) {
            ans += 'P';
            b = restore(b);
        } else if (is_sorted(b.begin(), b.end(), greater<ll>())) {
            ans += 'R';
            ans += 'P';
            b = restore(my_reverse(b));
        } else bad_result();
        ++ iteration;
    }

    reverse(ans.begin(), ans.end());
    return ans;

}

bool solve2(vector <ll> a, vector <ll> b) {

    ll tot = 0;
    vector <ll> ca = a, cb = b;

    while (true) {
        if (a == b || my_reverse(a) == b) break;
        if (!is_sorted(b.begin(), b.end()))
            reverse(b.begin(), b.end());

        if (b[0] <= 0) bad_result();

        if (b[0] == a[0]) {
            if ((b[1] - a[1]) % b[0] == 0) {
                tot += (b[1] - a[1]) / b[0];
                break;
            }
        }
        if (b[0] == a[1]) {
            if ((b[1] - a[0]) % b[0] == 0) {
                tot += (b[1] - a[0]) / b[0];
                break;
            }
        }


        ll former = b[1];
        b[1] %= b[0];
        tot += ((former - b[1]) / b[0]);
    }
    if (tot > LIM) {
        printf("BIG\n%lld\n", tot);
        return true;
    }

    return false;
}

vector <ll> a;
vector <ll> b;

string ans;

int main () {
    scanf("%d", &n);

    a.resize(n, 0LL);
    b.resize(n, 0LL);

    for (int i = 0 ; i < n ; ++ i)
        scanf("%lld", &a[i]);

    for (int i = 0 ; i < n ; ++ i)
        scanf("%lld", &b[i]);

    if (n == 1) {
        if (a == b) {
            return !printf("SMALL\n0");
        } else return !printf("IMPOSSIBLE");
    }

    if (n == 2) {
        if (solve2(a, b)) return 0;;
    }

    string result = naive(a, b);

    if (count(result.begin(), result.end(), 'P') > LIM) {
        puts("BIG\n");
        printf("%d\n", count(result.begin(), result.end(), 'P'));
        return 0;
    }

    puts("SMALL");
    printf("%d\n%s", int(result.size()), result.c_str());

}
/*
    Long time no see...
        CF round
*/