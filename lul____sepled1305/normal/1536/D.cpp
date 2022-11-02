#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        int pointer = 0;
        bool pass = true;
        set<int> st;
        int a;
        cin>>a;
        int last = a;
        st.insert(a);
        st.insert(-2e9);
        st.insert(2e9);
        for(int i=1;i<n;i++) {
            cin>>a;
            if(last == a) {
                continue;
            }
            if(last < a) {
                auto it = st.upper_bound(last);
                int suppose = *it;
                if(suppose < a) {
                    pass  = false;
                    continue;
                }
                if(suppose != a)
                    st.insert(a);
            }
            else {
                auto it = st.lower_bound(last);
                it--;
                int suppose = *it;
                if(suppose > a) {
                    pass  = false;
                    continue;
                }
                if(suppose != a)
                    st.insert(a);
            }
            last = a;
        }
        if(pass)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}