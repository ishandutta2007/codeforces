#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii = pair<int,int>

bool test(vector<int> &v, int k) {
    unordered_set<int> st;
    for(int i=0;i<v.size();i++) {
        if(k == 0) break;
        if(st.count(v[i]) == 0) {
            st.insert(v[i]);
            k--;
        }
    }
    bool pass = true;
    int last = 0, cur;
    for(int i=0;i<v.size();i++) {
        cur = v[i];
        if(st.count(v[i]))
            cur = 0;
        pass &= (last <= cur);
        last = cur;
    }
    return pass;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++) {
            int l; cin>>l;
            v.push_back(l);
        }
        int le = 0, ra = n;
        while(le < ra) {
            int md = le + ra >> 1;
            if(md == le) {
                if(test(v,le))
                    ra = le;
                else
                    le = ra;
            }
            else {
                if(!test(v,md))
                    le = md+1;
                else
                    ra = md;
            }
        }
        cout<<le<<endl;
    }
    return 0;
}