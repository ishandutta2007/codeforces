#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int n;
vector<pii> v;
int num;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {int h, a; cin >> h >> a; v.push_back(pii(h, a));}
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j) continue;
            if (v[i].first==v[j].second) num++;
        }
    }
    cout << num << endl;
}