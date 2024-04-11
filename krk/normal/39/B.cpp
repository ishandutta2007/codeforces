#include <iostream>
#include <vector>
using namespace std;

int n;
vector <int> V;

int main()
{
    cin >> n;
    int a, toseek = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a == toseek) { V.push_back(2000+i); toseek++; }
    }
    cout << V.size() << endl;
    if (!V.empty()) {
                    for (int i = 0; i < V.size(); i++) {
                        if (i) cout << " ";
                        cout << V[i];
                    }
                    cout << endl;
    }
    return 0;
}