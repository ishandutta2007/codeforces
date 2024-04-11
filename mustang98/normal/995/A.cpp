#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 55, inf = 1000111222;

int m[4][max_n];
int n;
int k = 0;

vector<pair<int, int> > ans;
vector<int> c;

void park(){
    for (int j = 0; j < n; ++j) {
        if (m[1][j] != 0 && m[0][j] == m[1][j]) {
            c.PB(m[1][j]);
            ans.PB(MP(0, j));
            m[1][j] = 0;
            --k;
        }
        if (m[2][j] != 0 && m[3][j] == m[2][j]) {
            c.PB(m[2][j]);
            ans.PB(MP(3, j));
            m[2][j] = 0;
            --k;
        }
    }
}
int cnt = 0;
void movee(int i, int j) {
    if (cnt == 2 * n - 1) return;
    cnt++;
    if (i == 1) {
        if (j == 0) {
            c.PB(m[2][0]);
            ans.PB(MP(i, j));
            swap(m[i][j], m[2][0]);
            movee(2, 0);
            return;
        }
        else {
            c.PB(m[1][j - 1]);
            ans.PB(MP(i, j));
            swap(m[i][j], m[1][j - 1]);
            movee(i, j - 1);
            return;
        }
    }
    if (i == 2) {
        if (j == n - 1) {
            c.PB(m[1][n - 1]);
            ans.PB(MP(i, j));
            swap(m[i][j], m[1][n - 1]);
            movee(1, n - 1);
            return;
        }
        else {
            c.PB(m[2][j + 1]);
            ans.PB(MP(i, j));
            swap(m[i][j], m[2][j + 1]);
            movee(i, j + 1);
            return;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin)
    cin >> n >> k;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }
    park();
    if (2 * n == k) {
        cout << -1;
        return 0;
    } else {
        while(k) {
            //cout << k << endl;
            park();
            int ei = -1, ej = -1;
            for (int i = 1; i <= 2; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (m[i][j] ==0) {
                        ei = i;
                        ej = j;
                        break;
                    }
                }
            }
          //  cout << ei << ' ' << ej << endl;
            cnt = 0;
            movee(ei, ej);
        }
        park();
    }
    vector<pair<int, int> > ans1;
    vector<int> c1;
    for (int i = 0; i < ans.size(); ++i) {
        if (c[i] == 0) continue;
        c1.PB(c[i]);
        ans1.PB(ans[i]);
    }
    if (ans1.size() > 20000) {
        cout << -1;
        return 0;
    }
    cout << ans1.size() << endl;
    for (int i = 0; i < ans1.size(); ++i) {
        cout << c1[i] << ' ' << ans1[i].F + 1 << ' ' << ans1[i].S + 1 << "\n";
    }


    return 0;
}


/*
5 4 1 0
1 3 5 0
2 4 6 0
6 3 2 0*/