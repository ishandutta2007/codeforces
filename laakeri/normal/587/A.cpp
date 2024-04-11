#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

ll a[2010101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int w;
        cin>>w;
        a[w]++;
    }
    for (int i=0;i<=2000000;i++){
        if (a[i]>1){
            a[i+1]+=a[i]/2;
            a[i]%=2;
        }
    }
    int v=0;
    for (int i=0;i<=2000000;i++){
        if (a[i]) v++;
    }
    cout<<v<<endl;
}