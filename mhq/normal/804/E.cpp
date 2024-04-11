#include <bits/stdc++.h>
using namespace std;
int n;
int p[150];
int op = 0;
void print(int a, int b) {
    op++;
    cout << a << " " << b << '\n';
    //swap(p[a], p[b]);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n % 4 == 2 || n % 4 == 3) {
        cout << "NO";
        return 0;
    }
    if (n == 1) {
        cout << "YES";
        return 0;
    }
    //for (int i = 1; i <= n; i++) p[i] = i;
    cout << "YES" << '\n';
    if (n % 4 == 0) {
        while (n > 4) {
            for (int i = 1; i <= (n - 4); i += 2) {
                print(i, n);
                print(i + 1, n - 1);
                print(i, n - 1);
                print(i + 1, n);
                print(i, n - 2);
                print(i + 1, n - 3);
                print(i, n - 3);
                print(i + 1, n - 2);
            }
            print(n - 3, n - 2);
            print(n - 1, n);
            print(n - 3, n - 1);
            print(n - 2, n);
            print(n - 3, n);
            print(n - 2, n - 1);
            n -= 4;
        }
        print(1, 2);
        print(3, 4);
        print(1, 4);
        print(2, 3);
        print(2, 4);
        print(1, 3);
        //cout << op;
        return 0;
    }
    for (int i = 1; i <= (n - 1); i += 2) {
        print(i, n);
        print(i, i + 1);
        print(i + 1, n);
    }
    n--;
    while (n > 4) {
        for (int i = 1; i <= (n - 4); i += 2) {
            print(i, n);
            print(i + 1, n - 1);
            print(i, n - 1);
            print(i + 1, n);
            print(i, n - 2);
            print(i + 1, n - 3);
            print(i, n - 3);
            print(i + 1, n - 2);
        }
        print(n - 3, n - 1);
        print(n - 2, n);
        print(n - 3, n);
        print(n - 2, n - 1);
        n -= 4;
    }
    print(1, 4);
    print(2, 3);
    print(2, 4);
    print(1, 3);
    //for (int i = 1; i <= 5; i++) cout << p[i] << " ";
    //cout << '\n';
    //cout << op;
    return 0;
}