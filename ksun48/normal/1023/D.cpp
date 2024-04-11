#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, q;
int check(vector<int> a){
    if(a.size() == 0) return 1;
    vector<int> st;
    vector<int> app(q+1, 0);
    for(int b : a){
        while(st.size() > 0 && st[st.size()-1] > b){
            st.pop_back();
        }
        if(app[b]){
            if(st.size() == 0 || st[st.size()-1] != b){
                return 0;
            }
        } else {
            st.push_back(b);
            app[b] = 1;
        }
    }
    return 1;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    vector<int> s(n);
    
    vector<int> a;
    int hasq = 0;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        if(s[i] == q) hasq = 1;
    }
    for(int i = 0; i < n; i++){
        if(s[i] == 0 && !hasq){
            s[i] = q;
        }
        if(s[i] == q) hasq = 1;
    }
    for(int i = 0; i < n; i++){
        if(s[i] > 0){
            a.push_back(s[i]);
        }
    }
    if(hasq && check(a)){
        cout << "YES" << '\n';
        if(a.size() == 0){
            s[0] = 1;
        }
        for(int i = 1; i < n; i++){
            if(s[i] == 0){
                s[i] = s[i-1];
            }
        }
        reverse(s.begin(), s.end());
        for(int i = 1; i < n; i++){
            if(s[i] == 0){
                s[i] = s[i-1];
            }
        }
        reverse(s.begin(), s.end());
        for(int i = 0; i < n; i++){
            cout << s[i] << " ";
        }
        cout << '\n';
    } else {
        cout << "NO" << '\n';
    }
}