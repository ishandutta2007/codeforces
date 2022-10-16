/*input
1
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
// const int N =;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); i++) if (x % i == 0) return false;
    return true;
}

int INF = 1e9;
int rINF = 1e18;
vector<int> primes;

void prep() {
    primes.clear();
    loop(i, 2, 880) {
        if (isPrime(i)) primes.push_back(i);
    }
}

struct GraderX {
    int num, cnt;
    void init(int T) {
        cnt = 0;
        if (T == 1) num = 998244353;
        else num = 4194304;
    }
    int ask(int X) {
        cnt++;
        return gcd(X, num);
    }
} Grader;

int asked = 0;
int ask(int x) {
    asked++;
#ifdef UncleGrandpa
    return Grader.ask(x);
#else
    cout << "?" << sp << x << endl;
    int ret; cin >> ret;
    return ret;
#endif
}

void answer(int x) {
    cout << "!" << sp << x << endl;
}

int gmax(int t) {
    int ret = 1;
    while (ret * t <= INF) {
        ret *= t;
    }
    return ret;
}

int numDiv(int x) {
    int ret = 1;
    loop(i, 2, 1000) {
        int cnt = 0;
        while (x % i == 0) {
            cnt++; x /= i;
        }
        ret *= (cnt + 1);
    }
    return ret;
}


signed main() {
    int T;
    cin >> T;
    loop(cT, 1, T) {
        // Grader.init(cT);
        prep();
        vector<int> pen;
        int i = 0, curNum = 1;
        asked = 0;
        while (true) {
            if (asked == 22) break;
            while (true) {
                int t = primes.back();
                if (t * t * t > INF / curNum) primes.pop_back();
                else break;
            }
            int toAsk = 1;
            if (!pen.empty()) {
                toAsk *= gmax(pen.back());
                pen.pop_back();
            }
            if (!pen.empty()) {
                toAsk *= gmax(pen.back());
                pen.pop_back();
                auto rec = ask(toAsk);
                curNum = rec * curNum / gcd(rec, curNum);
            }
            else {
                vector<int> just;
                while (i < primes.size()) {
                    auto it = primes[i];
                    if (toAsk <= rINF / it) {
                        toAsk *= it; just.push_back(it);
                        i++;
                    }
                    else break;
                }
                if (toAsk == 1) break;
                // print(toAsk);
                auto rec = ask(toAsk);
                curNum = rec * curNum / gcd(rec, curNum);
                for (auto it : just) {
                    if (rec % it == 0) pen.push_back(it);
                }
            }
        }
        // print(Grader.cnt);
        answer(numDiv(curNum) * 2);
    }
}