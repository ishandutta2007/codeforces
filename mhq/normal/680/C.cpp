#include <bits/stdc++.h>
using namespace std;
bool used[105];
bool ok;
vector <int> pr;
string x;
int ind;
int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 2; i <= 50; i++) {
        if (!used[i]) {
            pr.push_back(i);
        }
        for (int j = 2; i * j <= 50; j++) {
            used[i * j] = true;
        }
    }
    //cout << pr.size();
    for (int i = 0; i < pr.size(); i++) {
        if (!ok && pr[i] > 10) {
                cout << "prime" << endl;
                return 0;
        }
        cout << pr[i] << endl;
        cin >> x;
        if (x == "yes") {
            if (ok) {
                cout << "composite" << endl;
                return 0;
            }
            ok = true;
            ind = pr[i];
        }
    }
    cout << ind * ind << endl;
    cin >> x;
    if (x == "yes") cout << "composite" << endl;
    else cout << "prime" << endl;
    return 0;
}