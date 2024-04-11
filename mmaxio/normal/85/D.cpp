#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define long long long 

vector<int> v;
int n;
int main() {
    cin >> n;
    v.reserve(n);
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        if (s == "sum") {
            int l = v.size();
            long sum = 0;
            for(int i = 2; i < l; i += 5) {
                sum += v[i];
            }
            cout << sum << endl;
        } else {
            int x; cin >> x;
            if (s == "add") {               
                v.insert(lower_bound(v.begin(), v.end(), x), x);
            } else { // s == "del"
                v.erase(lower_bound(v.begin(), v.end(), x));
            }
        }
    }
}