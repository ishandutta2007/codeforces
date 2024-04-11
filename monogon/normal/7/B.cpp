
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int t, m, n, x;
string s;
int id = 1;
set<int> blocks;
int bytes[N], pos[N];
int arr[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t >> m;
    while(t--) {
        cin >> s;
        if(s == "alloc") {
            cin >> n;
            int cnt = 0, i = 0;
            for(; i < m; i++) {
                if(arr[i] == 0) cnt++;
                else cnt = 0;
                if(cnt == n) break;
            }
            if(cnt == n) {
                blocks.insert(id);
                bytes[id] = cnt;
                pos[id] = i - cnt + 1;
                fill(arr + i - cnt + 1, arr + i + 1, id);
                cout << id << endl;
                id++;
            }else {
                cout << "NULL" << endl;
            }
        }else if(s == "erase") {
            cin >> x;
            auto it = blocks.find(x);
            if(it == blocks.end()) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }else {
                blocks.erase(it);
                for(int i = 0; i < m; i++) {
                    if(arr[i] == x) arr[i] = 0;
                }
            }
        }else {
            // defragment
            int cnt = 0;
            for(int i = 0; i < m; i++) {
                if(arr[i] == 0) cnt++;
                else {
                    arr[i - cnt] = arr[i];
                    if(i - cnt < pos[arr[i]]) {
                        pos[arr[i]] = i - cnt;
                    }
                    if(cnt > 0) arr[i] = 0;
                }
            }
        }
    }
}