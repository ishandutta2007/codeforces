#include <bits/stdc++.h>
using namespace std;
int b[4][4];
int a[4][4];
long long k;
int A, B;
pair < int, int > T[300];
pair <int, int> ans (pair <int , int> x) {
    int m = x.first;
    int n = x.second;
    if ( m == n) {
        return make_pair(0, 0);
    }
    if ( m == 3 && n == 2)
        return make_pair(1, 0);
    if ( m == 2 && n == 1)
        return make_pair(1, 0);
    if ( m == 1 && n == 3)
        return make_pair(1, 0);
    return make_pair(0, 1);
}
int main()
{   ios_base::sync_with_stdio(0);
    cin >> k >> A >> B;
    for ( int i = 1; i <= 3; i++) {
        for ( int j = 1; j <= 3; j++){
            cin >> a[i][j];
        }
    }
    for ( int i = 1; i <= 3; i++) {
        for ( int j = 1; j <= 3; j++) {
            cin >> b[i][j];
        }
    }
    T[1].first = A;
    T[1].second = B;
    int x1, x2;
    bool mark1 = false;

    for ( int i = 1; i <= 200; i++) {
            T[i + 1].first = a[T[i].first][T[i].second];
            T[i + 1].second = b[T[i].first][T[i].second];
            for ( int j = 1; j <= i; j++) {
                if (T[i + 1] == T[j]) {
                    x1 = j;
                    x2 = i + 1;
                    mark1 = true;
                    break;
            }
        }
        if (mark1) break;
    }
    long long ansa = 0; long long ansb = 0;
    if ( k < x1 ) {
        for ( int i = 1; i <= k; i++) {
            ansa += ans(T[i]).first;
            ansb += ans(T[i]).second;
        }
        cout << ansa << " " <<ansb;
        return 0;
    }
    for ( int i = 1; i < x1; i++) {
        ansa += ans(T[i]).first;
        ansb += ans(T[i]).second;
    }
    pair<int, int> per = make_pair(0,0);
    for ( int i = x1; i <= x2 - 1; i++) {
        per.first += ans(T[i]).first;
        per.second += ans(T[i]).second;
    }
    long long l = ( k - x1 + 1)/(x2 - x1);
    ansa += per.first * l;
    ansb += per.second * l;
    k = k - l * (x2 - x1) - x1 + 1;
    for ( long long i = x1; i < x1 + k; i++) {
        ansa += ans(T[i]).first;
        ansb += ans(T[i]).second;
    }
    cout << ansa << " " << ansb;
    return 0;
}