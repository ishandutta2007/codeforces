#include <iostream>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length(), k;
    cin >> k;
    set<pair<string, int> > st;
    for(int i = 0; i < n; ++i)
            st.insert(make_pair(s.substr(i, 1), i));
    int cur = 0;        
    for(;!st.empty();) {
            cur++;
            if(cur == k) {
                   cout << st.begin()->first;
                   cin >> n;
                   return 0;
            }
            pair<string, int> pr = *st.begin();
            st.erase(st.begin());
            if(pr.second < n - 1) {
                          pr.first += s[++pr.second];
                          st.insert(pr);
            }
    }
    cout << "No such line." << endl;
    cin >> n;
    return 0;
}