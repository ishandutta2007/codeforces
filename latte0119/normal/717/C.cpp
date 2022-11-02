#include<bits/stdc++.h>

using namespace std;

struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}init;
typedef long long LL;
const LL MOD=10007;
int main(){
    int n;
    cin>>n;
    vector<LL> a(n);
    for(auto &it:a)cin>>it;
    sort(a.begin(),a.end());
    auto b=a;
    reverse(b.begin(),b.end());
    LL sum=0;
    for(int i=0;i<n;i++)
        (sum+=a[i]*b[i])%=MOD;
    cout<<sum<<endl;

}