#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef map<string, int, less<string> > map_type;
typedef map_type::iterator map_it;
typedef map_type::value_type val;

int main() {
    map_type mp;
    int n;
    cin >> n;
    string ans[n];
    int num[n];
    for(int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            if(mp.count(s) == 0) {
                           ans[i] = "OK";
                           num[i] = 0;
                           mp.insert(val(s, 1));
            }
            else {
                 pair<map_it, map_it> ii = mp.equal_range(s);
                 ans[i] = s;
                 num[i] = ii.first->second;
                 ii.first->second++;
            }
    }
    for(int i = 0; i < n; ++i) {
            cout << ans[i];
            if(num[i])
                      cout << num[i];
            cout << endl;
    }
    
    cin >> n;
    
    return 0;
}