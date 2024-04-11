#include <iostream>
#include <deque>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    deque<int> b;
    multiset<int> mset;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b.push_back(a[i]);
        mset.insert(a[i]);
    }
    if(*mset.begin() == *mset.rbegin()){
        cout <<(0) << endl;
        return 0;
    }

    for(int i = 0; i < 1000000; i++){
        b.push_back(b[k-1]);
        mset.insert(b[k-1]);
        mset.erase(mset.find(b[0]));
        b.pop_front();
        if(*mset.begin() == *mset.rbegin()){
            cout <<(i+1) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}