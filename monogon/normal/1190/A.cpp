
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_M = 1e5 + 5;
ll n, k;
int m;
ll p[MAX_M], page[MAX_M];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        cin >> p[i];
        p[i]--;
        page[i] = (p[i] - i) / k;
    }
    int i = 0;
    int deleted = 0;
    int ops = 0;
    while(i < m) {
        int j = i + 1;
        while(j < m && page[i] == page[j]) j++;
        // [i, j) are the indices which are deleted from page[i],
        // whether or not they start there.
        ll currpage;
        int prevdeleted = deleted;
        for(int l = i; l < j; l++) {
            currpage = (p[l] - deleted) / k;
            if(currpage > page[i]) {
                ops++;
                deleted = prevdeleted + l - i;
            }
        }
        ops++;
        deleted = j;
        i = j;
    }
    cout << ops << endl;
}