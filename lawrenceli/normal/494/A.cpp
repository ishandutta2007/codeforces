#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int n, num[MAXN];
char s[MAXN];

void print() {
    int a=0, b=0;
    vector<int> v;
    for (int i=0; i<n; i++) {
        if (s[i] == '(') a++;
        else if (s[i] == ')') b++;
        else {
            v.push_back(num[i]);
            b += num[i];
        }
        if (b > a) {
            cout << "-1\n";
            return;
        }
    }
    for (int i=0; i<v.size(); i++)
        printf("%d\n", v[i]);
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> s;
    n = strlen(s);

    int l=0, r=0, last=-1;
    for (int i=0; i<n; i++) {
        if (s[i] == '(') l++;
        else if (s[i] == ')') r++;
        else r++, last = i, num[i] = 1;
        if (l < r) {
            cout << "-1\n";
            return 0;
        }
    }

    if (l < r) {
        cout << "-1\n";
    } else {
        if (l == r) {
            print();
        } else {
            if (last == -1) cout << "-1\n";
            else {
                num[last] += l-r;
                print();
            }
        }
    }

}