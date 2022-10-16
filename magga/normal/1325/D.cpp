#include<bits/stdc++.h>
using namespace std;
unsigned long long int cach[64];
void pre(){
    cach[0]=1;
    for(long long int i=1;i<64;i++){
        cach[i]=2*cach[i-1];
    }
}

void solve(){
    long long int u,v;cin>>u>>v;
    string sm = std::bitset< 64 >( v ).to_string();
    string xr = std::bitset< 64 >( u ).to_string();
    unsigned long long int ans[3]{0};
    long long int flag[64]{0};
    long long int j = 0;
    for(long long int i=64;i>=0;i--){
        if(xr[i]=='0' && sm[i]=='0'){
            j++;
            continue;
        }
        if(xr[i]=='1' && sm[i]=='1'){
            ans[0]+=cach[j];
            flag[j]++;
            j++;
            continue;
        }
        if(xr[i]=='1' && sm[i]=='0'){
            if(j==0){
                cout<<-1<<"\n";
                return;
            }
            ans[flag[j-1]]+=cach[j-1];
            flag[j-1]++;
            ans[flag[j-1]]+=cach[j-1];
            flag[j-1]++;
            ans[0]+=cach[j];
            flag[j]++;
            j++;
            v-=cach[j];
            sm = std::bitset< 64 >( v ).to_string();
            if(v<0){
                cout<<-1<<"\n";
                return;
            }
            continue;
        }
        if(xr[i]=='0' && sm[i]=='1'){
            if(j==0){
                cout<<-1<<"\n";
                return;
            }
            ans[flag[j-1]]+=cach[j-1];
            flag[j-1]++;
            ans[flag[j-1]]+=cach[j-1];
            flag[j-1]++;
            j++;
        }
    }
    if(ans[0]==0){
        cout<<0<<"\n";
        return;
    }
    if(ans[1]==0){
        cout<<1<<"\n";
        cout<<ans[0]<<"\n";
        return;
    }
    if(ans[2]==0){
        cout<<2<<"\n";
        cout<<ans[0]<<" "<<ans[1]<<"\n";
        return;
    }
    cout<<3<<"\n";
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}