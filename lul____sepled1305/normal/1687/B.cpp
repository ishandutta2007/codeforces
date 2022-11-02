//
// Created by Nitit Jongsawatsataporn on 3/6/2022 AD.
//

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
int n,m;

void ask(int k) {
    cout<<"? ";
    for(int i=0;i<k;i++)
        cout<<'0';
    cout<<'1';
    for(int i=k+1;i<m;i++)
        cout<<'0';
    cout<<'\n';
    fflush(stdout);
}

int main() {
    cin>>n>>m;
    int a[m];
    pii v[m];
    for(int i=0;i<m;i++) {
        ask(i); cin>>a[i];
        v[i] = {a[i],i};
    }
    sort(v,v+m);
    string s;
    for(int i=0;i<m;i++)
        s.push_back('0');
    int cur = 0;
    for(int i=0;i<m;i++) {
        int val = v[i].first;
        int nd = v[i].second;
        s[nd] = '1';
        cout<<"? "<<s<<'\n';
        fflush(stdout);
        int nw; cin>>nw;
        if(nw < cur + a[nd]) {
            s[nd] = '0';
        }
        else {
            cur = nw;
        }
    }
    cout<<"! "<<cur<<'\n';
    fflush(stdout);
    return 0;
}