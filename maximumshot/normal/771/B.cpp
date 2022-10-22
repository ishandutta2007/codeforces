#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int n, k;

string getName(int x) {
    string res;
    for(int i = 0;i < 10;i++) {
        if((1 << i) & x) {
            res += "b";
        }else {
            res += "a";
        }
    }
    if(res[0] == 'a') {
        res[0] = 'A';
    }else {
        res[0] = 'B';
    }
    return res;
}

int res[55];

int main() {

    cin >> n >> k;

    for(int i = 0;i + 1 < k;i++) {
        res[i] = i;
    }

    for(int i = k - 1;i < n;i++) {
        string t;
        cin >> t;

        if(t == "YES") {
            set< int > q;
            for(int x = 0;x < k;x++) q.insert(x);
            for(int j = i - k + 1;j < i;j++) {
                q.erase(res[j]);
            }
            res[i] = *q.begin();
        }else { // t == "NO"
            res[i] = res[i - k + 1];
        }
    }

    for(int i = 0;i < n;i++) {
        cout << getName(res[i]) << " ";
    }
    cout << "\n";

    return 0;
}