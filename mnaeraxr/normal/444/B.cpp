#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 1;

int64 x;

int64 getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

int a[maxn], b[maxn], n, d;
int to[maxn];

void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> x;

    initAB();

    vector<int> pos;

    for (int i = 0; i < n; ++i){
        to[ a[i] ] = i;
        if (b[i]) pos.push_back(i);
    }

    int s = 42;

    for (int i = 0; i < n; ++i){
        bool found = false;
        for (int j = n; j >= max(n - s, 1); --j){
            if (to[j] <= i && b[ i - to[j] ]){
                cout << j << endl;
                found = true;
                break;
            }
        }

        if (!found){
            int ans = 0;
            for (int j = 0; j < (int)pos.size(); ++j){
                if (pos[j] > i) break;
                ans = max(ans, a[i - pos[j]]);
            }
            cout << ans << endl;
        }
    }


    return 0;
}