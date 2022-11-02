#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main() {
    string a, b;
    
    cin >> a >> b;
    
    set<int> pos[26];
    
    for(int i = 0; i < a.size(); ++i) 
            pos[a[i] - 'a'].insert(i);
    
    int res = 1, cur = -1;
    
    for(int i = 0; i < b.length(); ++i) {
            if(pos[b[i] - 'a'].empty()) {
                        cout << -1;
                        return 0;
            }
            set<int>::iterator ii = pos[b[i] - 'a'].lower_bound(cur + 1);
            if(ii == pos[b[i] - 'a'].end()) {
                  cur = *pos[b[i] - 'a'].begin();
                  ++res;
            }
            else
                cur = *ii;
    }

    cout << res << endl;
   
    cin >> a;
    return 0;
}