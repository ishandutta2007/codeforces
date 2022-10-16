#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 19;

int answer;

int freq[10];
int temp[10];

int A[maxn];
int B[maxn];
int C[maxn];

bool check(int c, bool X, bool Y){
    if ( (X && Y) || c == -1)
        return true;

    if (!X && !Y && A[c] == C[c]){
        if (!freq[ A[c] ]) return false;
        freq[A[c]]--;
        bool ans = check(c-1,X,Y);
        freq[A[c]]++;
        return ans;
    }

    for (int i = 0; i < 10; ++i){
        if (!X && i < A[c]) continue;
        if (!Y && i > C[c]) continue;
        if (!freq[i]) continue;

        freq[i]--;
        bool ans = check(c-1, X | (i > A[c]), Y | (i < C[c]));
        freq[i]++;
        if (ans) return true;
    }

    return false;
}

void bt(int d, int r){
    if (d == 10){
        if (check(maxn-1, false, false)){
            answer++;
            // for (int i = 0; i < 10; ++i)
            //     cout << freq[i] << " ";
            // cout << endl;
        }
        return;
    }

    for (int i = 0; i <= r; ++i){
        freq[0] -= i;
        freq[d] += i;

        bt(d+1, r-i);

        freq[0] += i;
        freq[d] -= i;
    }
}

void read(int D[maxn]){
    int64 n; cin >> n;
    for (int i = 0; n; ++i){
        D[i] = n % 10;
        n /= 10;
    }
}

// total: 4686825

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif

    read(A);
    read(C);

    answer = 0;
    // for (int i = 0; i < maxn; ++i)
    //     cout << A[i] << " " << C[i] << endl;
    // exit(0);

    freq[0] = maxn;
    bt(1,18);

    cout << answer << endl;

    return 0;
}