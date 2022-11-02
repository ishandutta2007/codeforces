#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=18;i>=0;i--){
        if ((1<<i)<=n){
            cout<<i+1<<" ";
            n-=(1<<i);
        }
    }
}