#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

void my_random_shuffle(vector<int64> &a){
    for (int i = (int)a.size() - 1; i; --i){
        int u = rand() % (i+1);
        swap(a[u], a[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    srand(27081995);

    int n; cin >> n;

    vector<int64> value(n);

    for (int i = 0; i < n; ++i){
        cin >> value[i];
    }

    int64 answer = 1;
    
    set<int64> tested;
    set<int64> seen;

    for (int i = 0; i < n; ++i){
        if (1. * clock() / CLOCKS_PER_SEC > 3.7)
            break;

        int idx = (rand()) % (n - i);
        int64 u = value[idx];
        swap(value[idx], value[n - i - 1]);

        if (seen.find(u) != seen.end())
            continue;
        seen.insert(u);

        map<int64,int> freq;

        for (int k = 0; k < n; ++k)
            freq[__gcd(value[k], u)]++;

        auto iscorrect = [&](int64 d){
            if (tested.find(d) != tested.end())
                return false;
            tested.insert(d);

            int tmp = 0;
            for (auto p : freq)
                if (p.first % d == 0){
                    tmp += p.second;
                    if (tmp * 2 >= n)
                        return true;
                }
            return false;
        };

        for (int64 v = 1; v * v <= u; ++v){
            if (u % v == 0){
                if (v > answer && iscorrect(v)) 
                    answer = v;
                if (u / v > answer && iscorrect(u / v))
                    answer = u / v;
            }
        }
    }

    cout << answer << endl;

    return 0;
}