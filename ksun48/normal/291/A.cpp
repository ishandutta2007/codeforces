#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    multiset<int> stuff;
    for(int i = 0; i < n; i++){
        cin >> k;
        if(k>0) stuff.insert(k);
    }
    int r = 0;
    for(multiset<int>::iterator it = stuff.begin(); it != stuff.end(); it++){
        if(stuff.count(*it) >= 3){
            cout << -1 << endl;
            return 0;
        } else if(stuff.count(*it) == 2){
            r++;
        }
    }
    cout << r/2 << endl;
    return 0;
}