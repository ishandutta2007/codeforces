# include <iostream>
# include <cstdio>
# include <set>

using namespace std;

int a[100010];

set<int> e;

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        e.insert(i);
    }
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(e.find(a[i]) != e.end())
            e.erase(a[i]);
        else a[i] = -1;
    }
    for(int i = 0; i < n; ++i) {
        if(a[i] == -1) {
            a[i] = *e.begin();
            e.erase(e.begin());
        }
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}