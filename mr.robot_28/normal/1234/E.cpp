#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mt make_tuple
 
using namespace std;
 
const int N = 200110;
const ll mod = 1e9 + 7;
 
int main(){
    ll n,m, mi, ma, sum = 0;
    ll arr[N], cum[N] = {0};
    cin>>n>>m;
    for(int i=0;i<m;i++)    cin>>arr[i];
    for(int i=0;i<m-1;i++){
        mi = min(arr[i], arr[i+1]);
        ma = max(arr[i], arr[i+1]);
        sum += ma - mi;
        if(ma != mi){
            cum[mi] += mi - 1;
            cum[mi+1] -= mi - 1;
 
            cum[mi+1]--;
            cum[ma]++;
            
            cum[ma] += mi - (ma - mi);
            cum[ma+1] -= mi - (ma - mi);
        }
    }
    for(int i=1;i<=n;i++){
        sum += cum[i];
        cout<<sum<<" ";
    }
    cout<<endl;
    return 0;
}