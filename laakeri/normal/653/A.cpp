#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int h[1010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        h[a]=1;
    }
    for (int i=2;i<=1000;i++){
        if (h[i-1]==1&&h[i]==1&&h[i+1]==1){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
}