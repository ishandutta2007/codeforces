#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000011, inf = 1000111222;

bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int next_prime(int number) {
    for (int i = number + 1; ; ++i) {
        if (is_prime(i)) {
            return i;
        }
    }
}

        int p_second = next_prime(100 + rand() % 500);
        int mod = next_prime(1000000000 + rand() % 100000);

class Hash {
public:
    Hash() {
    }

    Hash(const std::string &str, char min_c = 'a') {

        int p_first = 3;


        h_first.resize(str.length());
        h_second.resize(str.length());
        pw_first.resize(str.length());
        pw_second.resize(str.length());

        pw_first[0] = 1;
        pw_second[0] = 1;
        for (int i = 1; i < str.length(); ++i) {
            pw_first[i] = pw_first[i - 1] * p_first;
            pw_second[i] = (1LL * pw_second[i - 1] * p_second) % mod;
        }

        h_first[0] = str[0] - min_c + 1;
        h_second[0] = str[0] - min_c + 1;
        for (int i = 1; i < str.length(); ++i) {
            h_first[i] = h_first[i - 1] * p_first + str[i] - min_c + 1;
            h_second[i] = (1LL * h_second[i - 1] * p_second + str[i] - min_c + 1) % mod;
        }
    }

    void operator = (const std::string &str) {
        *this = Hash(str);
    }

    pair<ll, ll> get_hash(int left, int right) {
        long long first = h_first[right], second = h_second[right];
        if (left) {
            first -= h_first[left - 1] * pw_first[right - left + 1];
            second -= (1LL * h_second[left - 1] * pw_second[right - left + 1]) % mod;
            if (second < 0) {
                second += mod;
            }
        }
        return MP(first, second);
    }

private:
    std::vector<long long> h_first, pw_first;
    std::vector<int> h_second, pw_second;
    int mod;
} h, hr;


char buf[max_n];
int n;
string s;

bool is_pal(int l, int r) {
    return h.get_hash(l, r) == hr.get_hash(n - r - 1, n - l - 1);
}

string read_str() {
    scanf("%s", buf);
    return buf;
}

string solve() {
    if (is_pal(0, n - 1)) {
        return s;
    }
    int mxc = 0;
    for (int i = 0; i < n; ++i) {
        int j = n - i - 1;
        if (j <= i) {
            break;
        }
        if (s[i] != s[j]) {
            break;
        }
        mxc = i + 1;
    }
    int mxp = 0;
    int l = mxc, r = n - mxc - 1;
    for (int k = r; k >= l; --k) {
        if (is_pal(k, r)) {
            mxp = r - k + 1;
        }
    }
    int BP, BM, B;
    BP = mxc;
    BM = mxp;
    B = BP * 2 + BM;
    for (int bp = mxc - 1; bp >= 0; --bp) {
        --l;
        ++r;
        int curp = mxp + 2;
        while(!is_pal(r - curp + 1, r)) {
            --curp;
        }
        mxp = curp;
        if (bp * 2 + mxp > B) {
            B = bp * 2 + mxp;
            BP = bp;
            BM = mxp;
        }
    }
    string res;
    for (int i = 0; i < BP; ++i) {
        res += s[i];
    }
    for (int i = 0; i < BM; ++i) {
        res += s[n - BP - BM + i];
    }
    for (int i = 0; i < BP; ++i) {
        res += s[n - BP + i];
    }
    return res;
}

int main()
{
            srand(chrono::steady_clock::now().time_since_epoch().count());
    //freopen("input.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while(t--) {
        s = read_str();
        n = s.size();
        h = Hash(s);
        reverse(s.begin(), s.end());
        hr = Hash(s);
        reverse(s.begin(), s.end());
        string s1 = solve();
        swap(h, hr);
        reverse(s.begin(), s.end());
        string s2 = solve();
        if (s1.size() > s2.size()) {
            printf("%s\n", s1.c_str());
        } else {
            printf("%s\n", s2.c_str());
        }
    }

    return 0;
}