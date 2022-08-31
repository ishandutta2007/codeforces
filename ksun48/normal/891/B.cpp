#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n;
    cin >> n;
    int a[n];
    vector<int> st;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        st.push_back(a[i]);
    }
    sort(st.begin(), st.end());
    map<int,int> v;
    for(int i = 0; i < n; i++){
        v[st[i]] = st[(i+1)%n];
    }
    for(int i = 0; i < n; i++){
        cout << v[a[i]] << " ";
    }
    cout << endl;
}