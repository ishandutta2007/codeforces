#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t;
    pair <int,int> a[4];
    cin>>t;
    for(i=0;i<t;i++) {
        for(j=0;j<4;j++) {
            cin>>k;
            a[j]=make_pair(k,j);
        }
        sort(a,a+4);
        if (a[2].second<2&&a[3].second<2) {
            cout<<"NO\n";
        }
        else if (a[2].second>1&&a[3].second>1) {
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
        }
    }
    return 0;
}