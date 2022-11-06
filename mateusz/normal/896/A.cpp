#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

unsigned long long len[N];

int main() {
    
    ios_base::sync_with_stdio(0);
    string beginning = "What are you doing while sending \"";
    string middle = "\"? Are you busy? Will you send \"";
    string ending = "\"?";
    
    string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
    len[0] = f0.size();
    for (int i = 1; i <= 100000; i++) {
        len[i] = min((unsigned long long)1e18, beginning.size() + len[i - 1] + middle.size() + len[i - 1] + ending.size());
    }
    
    
    int n, q;
    long long k;
    
    cin >> q;
    while (q--) {
        cin >> n >> k;
        k--;
        while (true) {
            if (k >= len[n]) {
                cout << ".";
                break;
            }
            if (n == 0) {
                cout << f0[k];
                break;
            }
            if (k < beginning.size()) {
                cout << beginning[k];
                break;
            }
            k -= beginning.size();
            if (k < len[n - 1]) {
                n--;
                continue;
            }
            k -= len[n - 1];
            if (k < middle.size()) {
                cout << middle[k];
                break;
            }
            k -= middle.size();
            if (k < len[n - 1]) {
                n--;
                continue;
            }
            k -= len[n - 1];
            assert(k < ending.size());
            cout << ending[k];
            break;
        }
    }
    
    
    return 0;
}