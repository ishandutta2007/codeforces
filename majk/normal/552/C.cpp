#include <iostream>
#include <vector>

using namespace std; 

typedef long long ll;

int main() {
    int W,M; cin >> W >> M;
    if (W == 2) {
        cout << "YES\n";
        return 0;
    }
    
    vector<int> R;
    while (M) {
        int r = M%W;
        R.push_back(r);
        M /= W;
    }
    R.push_back(0);
    
    for (int i = 0; i < R.size(); ++i) {
        if (R[i] == W) { R[i] = 0; R[i+1]++; }  
        if (R[i] != 0 && R[i] != 1 && R[i] != W-1) {
            cout << "NO\n";
            return 0;
        }
        if (R[i] > 1) { R[i+1]++; }
    }


    cout << "YES\n";
}