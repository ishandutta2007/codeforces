#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

char A[maxn];
char B[maxn];
char T[maxn];

vector<int> actions;

void myreverse(int x, int n){
    actions.push_back(x);

    for (int i = 0; i < x; ++i)
        T[i] = A[n - i - 1];
    for (int i = 0; i < n - x; ++i)
        T[x + i] = A[i];
    for (int i = 0; i < n; ++i)
        A[i] = T[i];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int n; cin >> n;

    cin >> A >> B;

    for (int i = 0; i < n; ++i){
        if (i % 2 == 0){
            int p = i;

            while (p < n && A[p] != B[i])
                p++;

            if (p == n){
                cout << -1 << endl;
                return 0;
            }

            int sp = i;
            int sx = p - i;
            int ss = 1;
            int sy = n - sp - sx - ss;

            myreverse(ss + sy, n);
            myreverse(ss + sp + sx, n);
            myreverse(sy, n);
        }else{
            int p = n - i - 1;

            while (p >= 0 && A[p] != B[i])
                p--;

            if (p == -1){
                cout << -1 << endl;
                return 0;
            }

            int sp = i;
            int sx = p;
            int ss = 1;
            int sy = n - sp - sx - ss;

            myreverse(sp + sy, n);
            myreverse(ss, n);
        }
    }

    if (n % 2 == 0)
        myreverse(n, n);

    cout << actions.size() << endl;

    for (auto a : actions)
        cout << a << " ";
    cout << endl;

#ifdef MARX
    for (int i = 0; i < n; ++i)
        cout << A[i];
    cout << endl;
    for (int i = 0; i < n; ++i)
        cout << B[i];
    cout << endl;
#endif


    return 0;
}