#include <iostream>
#include <vector>

#define forn(i,n) for(int i = 0; i < int(n); ++i)

using namespace std;

int main() {

    int n, v;
    cin >> n >> v;

    vector <int> ans;

    forn(i, n) {
        bool u = false;
        int k, s;
        cin >> k;

        forn(j, k) {
            cin >> s;
            if (!u && v > s) {
                u = true;
                ans.push_back(i);
            }
        }
    }

    cout << ans.size() << endl;
    forn(i, ans.size())
        cout << ans[i]+1 << " ";
    
    return 0;
}