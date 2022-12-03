#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    long long a[200010];
    pair <int,int> c[200010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        sort(a,a+n);
        for(j=1;j<n;j++) {
            c[j-1]=make_pair(a[j]-a[j-1],j);
        }
        sort(c,c+n-1);
        cout<<a[c[0].second-1]<<' ';
        for(j=c[0].second+1;j<n;j++) {
            cout<<a[j]<<' ';
        }
        for(j=0;j<c[0].second-1;j++) {
            cout<<a[j]<<' ';
        }
        cout<<a[c[0].second]<<endl;
    }
    return 0;
}