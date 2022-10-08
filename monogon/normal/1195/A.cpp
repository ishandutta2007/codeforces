
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 1005;
int n, k, a, cnt[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a;
        cnt[a - 1]++;
    }
    int num = (n + 1) / 2;
    int stud = 0;
    for(int i = 0; i < k && num > 0; i++) {
        while(cnt[i] >= 2 && num > 0) {
            cnt[i] -= 2;
            num--;
            stud += 2;
        }
    }
    for(int i = 0; i < k && num > 0; i++) {
        if(cnt[i] > 0) {
            num--;
            stud++;
        }
    }
    cout << stud << endl;
}