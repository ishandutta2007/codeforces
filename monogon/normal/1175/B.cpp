
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
string str;
stack<ll> st;
ll t;
ll max_num = (((ll) 1) << 32) - 1;

int main() {
    cin >> n;
    st.push(0);
    while(n--) {
        cin >> str;
        if(str == "add") {
            ll num = st.top();
            st.pop();
            if(num + 1 > max_num) {
                cout << "OVERFLOW!!!" << endl;
                return 0;
            }
            st.push(num + 1);
        }else if(str == "for") {
            cin >> t;
            st.push(t);
            st.push(0);
        }else if(str == "end") {
            ll num = st.top();
            st.pop();
            t = st.top();
            st.pop();
            ll num2 = st.top();
            st.pop();
            if(t * num > max_num || num2 + t * num > max_num) {
                cout << "OVERFLOW!!!" << endl;
                return 0;
            }
            st.push(num2 + t * num);
        }
    }
    cout << st.top() << endl;
}