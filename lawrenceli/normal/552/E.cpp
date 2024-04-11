#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5005;

//a - value, b - 0 if +, 1 if *
int n, a[MAXN], b[MAXN];
ll p[MAXN], q[MAXN];
string s;
ll ans;

void go() {
    for (int i=0; i<n; i++) {
        a[i] = s[2*i]-'0';
        if (i) b[i] = s[2*i-1] == '*';

        p[i+1] = 1;
        int j;
        for (j=i; b[j]; j--) p[i+1] *= a[j];
        p[i+1] *= a[j];
        p[i+1] += p[j];
    }

    ans = max(ans, p[n]);
    for (int i=0; i<n; i++)
        if (b[i]) {
            q[i] = 0;
            for (int j=i; j<n; j++) {
                q[j+1] = 1;
                int k;
                for (k=j; b[k] && k>i; k--) q[j+1] *= a[k];
                q[j+1] *= a[k];
                q[j+1] += q[k];
                ll cur = q[j+1];
                int l = i-1, r = j+1;
                for (; b[l]; l--) cur *= a[l];
                cur *= a[l];
                for (; r<n && b[r]; r++) cur *= a[r];
                ans = max(ans, cur+p[l]+p[n]-p[r]);
            }
        }
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> s;
    n = s.length()/2+1;
    go();
    reverse(s.begin(), s.end());
    go();
    cout << ans;
}