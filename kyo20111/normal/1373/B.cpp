#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
string s;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    while(t--){
        cin >> s;
        stack<char> st;
        int c = 0;
        for(int i=0;i<s.size();i++){
            if(st.empty() || st.top() == s[i]) st.push(s[i]);
            else c++, st.pop();
        }
        cout << (c%2 ? "DA" : "NET") << '\n';
    }
}