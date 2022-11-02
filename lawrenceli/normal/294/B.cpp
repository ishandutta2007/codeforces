#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define rep(i, n) for (int i=0, _##i=(n); i<_##i; i++)

const int INF = (int)1e9;

int n;
vector<int> v1, v2;
int best=INF;

int main() {
    //freopen("294B.in", "r", stdin);
    cin >> n;
    rep(i, n) {
        int t, w;
        cin >> t >> w;
        if (t==1) v1.push_back(w);
        else v2.push_back(w);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    rep(i, v1.size()+1) {
        rep(j, v2.size()+1) {
            int w1=0, w2=v1.size()-i+2*(v2.size()-j);
            for (int k=0; k<i; k++) w1+=v1[k];
            for (int k=0; k<j; k++) w1+=v2[k];
            if (w2>=w1) best=min(best, w2);
        }
    }
    cout << best << endl;
}