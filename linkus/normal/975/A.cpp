#include <bits/stdc++.h>
typedef int64_t ll;
#define e1 first
#define e2 second
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    string s[n];
    set<string> st;
    for(int i = 0; i < n; ++i){
        cin >> s[i];
        sort(s[i].begin(),s[i].end());
        string s2;
        s2 += s[i][0];
        for(int x = 1; x < (int)s[i].size(); ++x){
            if(s[i][x] != s[i][x-1]) s2 += s[i][x];
        }
        /* cerr << s2 << '\n'; */
        st.insert(s2);
    }
    cout << st.size() << '\n';
}