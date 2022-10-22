#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int k;
string s;
vec< int > arr;

bool check(int w) {
    int cnt = 1;
    int cur = 0;
    for(int x : arr) {
        if(x > w) return false;
        if(cur + x <= w) {
            cur += x;
        }else {
            cur = x;
            cnt++;
        }
    }
    return cnt <= k;
}

int main() {

    cin >> k;

    getline(cin, s);
    getline(cin, s);

    for(int i = 0;i < (int)s.size();i++) {
        int j = i;
        while(j < (int)s.size() && s[j] != '-' && s[j] != ' ') j++;
        if(j == (int)s.size()) j--;
        arr.push_back(j - i + 1);
        i = j;
    }

    int bl = 1;
    int br = (int)s.size();
    int bm;

    while(br - bl > 1) {
        bm = (bl + br) / 2;
        if(check(bm)) br = bm;
        else bl = bm + 1;
    }

    if(bl < br && check(bl)) {
        cout << bl << "\n";
    }else {
        cout << br << "\n";
    }

    return 0;
}