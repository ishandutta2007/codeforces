#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int a[202020];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int, int> > lol(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
        lol[i]={a[i]-(n-i), i};
    }
    sort(lol.begin(), lol.end());
    for (int i=0;i<n;i++){
        a[lol[i].S]+=lol[i].S-i;
        if (i&&a[lol[i].S]<a[lol[i-1].S]){
            cout<<":("<<endl;
            return 0;
        }
    }
    for (int i=0;i<n;i++){
        cout<<a[lol[i].S]<<" ";
    }
}