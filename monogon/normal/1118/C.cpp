
#include <bits/stdc++.h>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORK(i, k, n) for(int i = k; i < n; i++)
#define FORr(i, n) for(int i = n - 1; i >= 0; i--)
#define FORKr(i, k, n) for(int i = n - 1; i >= k; i--)
#define PRINT(a, b) copy((a), (b), ostream_iterator<int>(cout, " "))
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define sz(a) ((int) (a).size())
#define Mp make_pair
#define PII pair<int, int>
#define LL long long
#define VI vector<int>

using namespace std;

// n even
// 4 copies of each number (n^2 / 4)

// n odd = 2k + 1
// 4 copies of each number in (k^2)
// 2 copies of each number in (k)
// 1 copy of one extra number

// X is k by k, Y is 1 by k, Z is 1 by 1

// X Y X
// Y Z Y
// X Y X

// if n is odd, fill Z first, then Y's, then X's.
// if n is even, everything is X

int mycount[1001];

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    VI a(n * n);
    FOR(i, n * n) {
        cin >> a[i];
        mycount[a[i]]++;
    }
    int center = -1;
    VI edge, block;
    if(n % 2 == 1) {
        FORK(i, 1, 1001) {
            if(mycount[i] % 2 == 1) {
                center = i;
                mycount[i]--;
                break;
            }
        }
        if(center == -1) {
            cout << "NO" << endl;
            return 0;
        }
        FORK(i, 1, 1001) {
            if(mycount[i] % 4 == 2) {
                edge.push_back(i);
                mycount[i] -= 2;
                if(edge.size() > n - 1) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        for(int i = 1; i <= 1000 && edge.size() < n - 1; i++) {
            while(mycount[i] % 4 == 0 && mycount[i] > 0 && edge.size() < n - 1) {
                edge.push_back(i);
                edge.push_back(i);
                mycount[i] -= 4;
                if(edge.size() > n - 1) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        if(edge.size() < n - 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    FORK(i, 1, 1001) {
        while(mycount[i] > 0 && mycount[i] % 4 == 0) {
            block.push_back(i);
            mycount[i] -= 4;
        }
    }
    if(block.size() < (n / 2) * (n / 2)) {
        cout << "NO" << endl;
        return 0;
    }
    // b[0], b[1], b[2], e[0], b[2], b[1], b[0]
    // b[3], b[4], b[5], e[1], b[5], b[4], b[3]
    // b[6], b[7], b[8], e[2], b[8], b[7], b[6]
    // e[3], e[4], e[5], c,    e[5], e[4], e[3]
    // b[6], b[7], b[8], e[2], b[8], b[7], b[6]

    cout << "YES" << endl;
    FOR(i, n / 2) {
        FOR(j, n / 2) {
            cout << block[i * (n / 2) + j] << " ";
        }
        if(n % 2 == 1) {
            cout << edge[i] << " ";
        }
        FORr(j, n / 2) {
            cout << block[i * (n / 2) + j] << " ";
        }
        cout << endl;
    }
    if(n % 2 == 1) {
        FOR(i, n / 2) {
            cout << edge[n / 2 + i] << " ";
        }
        cout << center << " ";
        FORr(i, n / 2) {
            cout << edge[n / 2 + i] << " ";
        }
        cout << endl;
    }
    FORr(i, n / 2) {
        FOR(j, n / 2) {
            cout << block[i * (n / 2) + j] << " ";
        }
        if(n % 2 == 1) {
            cout << edge[i] << " ";
        }
        FORr(j, n / 2) {
            cout << block[i * (n / 2) + j] << " ";
        }
        cout << endl;
    }
}