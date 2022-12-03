#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t;
    long long a[200010],b[200010];
    set <int> p;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        p.clear();
        cin>>a[0];
        k=0;
        p.insert(a[0]);
        for(j=1;j<n;j++) {
            cin>>a[j];
            if (p.upper_bound(a[j-1])!=p.end()&&*p.upper_bound(a[j-1])<a[j]) {
                k=1;
            }
            if (p.upper_bound(a[j])!=p.end()&&*p.upper_bound(a[j])<a[j-1]) {
                k=1;
            }
            p.insert(a[j]);
        }
        if (k) {
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
        }
    }
    return 0;
}