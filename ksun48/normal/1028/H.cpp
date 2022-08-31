#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1000000007;
vector<int> hs(6000000, 0);

vector<int> primes(int a){
    vector<int> pr;
    for(int p = 2; p * p <= a; p++){
        while(a % (p*p) == 0) a /= (p*p);
        if(a % p == 0){
            a /= p;
            pr.push_back(p);
        }
    }
    if(a > 1) pr.push_back(a);
    return pr;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int> > stuff(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        stuff[i] = primes(a);
        assert(stuff[i].size() <= 7);
    }
    vector<vector<int> > prev_divisor(5100100, vector<int>(8, -1) );
    vector<vector<int> > closest(n, vector<int>(16, -1));
    for(int i = 0; i < n; i++){
        if(i > 0) closest[i] = closest[i-1];
        for(int b = 0; b < (1 << stuff[i].size()); b++){
            int prod = 1;
            for(int r = 0; r < stuff[i].size(); r++){
                if(b & (1 << r)) prod *= stuff[i][r];
            }
            int dist1 = stuff[i].size() - __builtin_popcount(b);
            for(int g = 0; g <= 7; g++){
                int idx = prev_divisor[prod][g];
                int& c = closest[i][g + dist1];
                c = max(c, idx);
            }
            prev_divisor[prod][dist1] = i;
        }
    }

    vector<pair<int,int> > queries(q);
    for(int t = 0; t < q; t++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        int ans = -1;
        for(int a = 0; a < 16; a++){
            if(closest[r][a] >= l){
                ans = a;
                break;
            }
        }
        cout << ans << '\n';
    }
}