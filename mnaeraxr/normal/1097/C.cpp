#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    map<int,int> C, O;
    int zero = 0;

    for (int i = 0; i < n; ++i){
        int closing = 0, open = 0;

        string s; cin >> s;

        for (auto c : s){
            if (c == ')'){
                if (open)
                    open--;
                else
                    closing++;
            }
            else{
                open++;
            }
        }

        if (closing == 0 && open == 0){
            zero++;
        }
        else if (closing == 0){
            O[open]++;
        }
        else if (open == 0){
            C[closing]++;
        }
    }

    int answer = zero / 2;

    for (auto p : C){
        answer += min(p.second, O[p.first]);
    }

    cout << answer << endl;

    return 0;
}