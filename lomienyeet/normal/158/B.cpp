#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    int freq[5]={};
    while(n--){
        int x;
        cin>>x;
        freq[x]++;
    }
    freq[1]=max(0ll,freq[1]-freq[3]);
    cout<<freq[3]+freq[4]+(freq[1]+freq[2]*2+3)/4<<"\n";
}