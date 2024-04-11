#include<bits/stdc++.h>
using namespace std;
map<int,int> leaf;
map<int,int> one;
set<pair<int,int>> st;

int main() {
    int n;
    cin>>n;
    //Root tree at 0
    int d[n];
    cout<<"? "<<1<<"\n"; fflush(stdout);
    int counti = 0;
    for(int i=0;i<n;i++) {
        cin>>d[i];
        if(d[i] == 1)
            st.insert({0,i});
    }
    int odd = 0, even = 0;
    for(int i=1;i<n;i++) {
        if(d[i]%2 == 0)
            even++;
        else
            odd++;
    }
    int rmd;
    if(odd > even)
        rmd = 0;
    else
        rmd = 1;
    for(int i=1;i<n;i++) {
        if(d[i]%2 == rmd) {
            cout<<"? "<<i+1<<"\n"; fflush(stdout);
            int v[n];
            for(int j=0;j<n;j++) {
                cin>>v[j];
                if(v[j] == 1)
                    st.insert({j,i});
            }
        }
    }
    cout<<"!\n";
    for(const pair<int,int> &it: st) {
        cout<<it.first+1<<' '<<it.second+1<<endl;
    }
    fflush(stdout);
    return 0;
}