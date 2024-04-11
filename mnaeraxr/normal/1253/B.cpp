#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

void no(){
    cout << -1 << endl;
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> answer;

    set<int> inside;
    set<int> here;

    int total = 0;

    for (int i = 0; i < n; ++i){
        int v; cin >> v;
        ++total;

        if (v > 0) {
            if (here.find(v) != here.end()) {
                no();
            }

            here.insert(v);
            inside.insert(v);
        } else {
            v *= -1;

            if (inside.find(v) == inside.end())
                no();

            inside.erase(v);

            if (inside.empty()) {
                answer.push_back(total);
                inside.clear();
                here.clear();
                total = 0;
            }
        }
    }

    if (total) no();

    cout << answer.size() << endl;
    for (auto x : answer)
        cout << x << " ";
    cout << endl;

    return 0;
}