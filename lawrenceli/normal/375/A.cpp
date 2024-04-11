#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

string nums[10], ans;
int perm[5] = {1, 6, 8, 9};
int freq[10];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    do {
        int sum = perm[3] + perm[2] * 10 + perm[1] * 100 + perm[0] * 1000;
        sum %= 7;
        nums[sum] = "";
        for (int i=0; i<4; i++) nums[sum] += perm[i] + '0';
    } while (next_permutation(perm, perm + 4));
    string a; cin >> a;
    for (int i=0; i<a.length(); i++) freq[a[i] - '0'] ++;
    for (int i=0; i<4; i++) freq[perm[i]] --;
    int sum = 0, cur = 1;
    for (int i=9; i>=0; i--) {
        for (int j=0; j<freq[i]; j++) {
            sum = (sum + i * cur) % 7;
            cur = (cur * 10) % 7;
        }
    }
    sum = (sum * 10000) % 7;
    for (int i=1; i<10; i++) {
        for (int j=0; j<freq[i]; j++) {
            ans += i + '0';
        }
    }
    ans += nums[(7 - sum) % 7];
    for (int i=0; i<freq[0]; i++) ans += '0';
    cout << ans << endl;
    return 0;
}