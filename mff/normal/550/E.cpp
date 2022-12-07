#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const double EPS = 1e-9;
const int oo = 0x3f3f3f3;
const int MAXN = (int)1e5 + 10;

int V[MAXN];

void print(int cur, int n)
{
    if (n == 0){
        cout << V[cur];
    }
    else{
        cout << "(";
        cout << V[cur];
        cout << "->";
        print(cur + 1, n - 1);
        cout << ")";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;


    int tot = 0;

    for (int i = 0; i < n; ++i){
        cin >> V[i];
        if (!V[i]) ++tot;
    }

    if (n == 1){
        if (V[0] == 0)
            cout << "YES" << endl << 0 << endl;
        else
            cout << "NO" << endl;
        return 0;

    }

    if (V[n - 1] == 1 || (V[n - 2] == 0 && tot == 2)){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    print(0, n - 2);
    cout << "->0" << endl;



    return 0;
}