#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        bool neg = false;
        set<int> st;
        for(int i=0;i<n;i++) {
            int a;
            cin>>a;
            if(a < 0) neg = true;
            st.insert(a);
        }
        if(neg)
            cout<<"NO\n";
        else {
            cout<<"YES\n";
            cout<<"300\n";
            int pointer = 0;
            for(int i=0;i<300;i++) {
                cout<<pointer<<' ';
                pointer++;
            }
            cout<<"\n";
        }
    }
}