#include<bits/stdc++.h>
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
void solve(){
    int n,d;cin>>n;
    int parity[2]{0};
    for(int i=0;i<n;i++){
        cin>>d;
        parity[1&d]++;
    }
    cout<<min(parity[0],parity[1])<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin>>T;
    for(long long int i=0;i<T;i++){
        solve();
    }   
}