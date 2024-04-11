#include<bits/stdc++.h>
using namespace std;
int N;
const int MAXN = 100010;
vector<int> P;
int ck[MAXN];
void solve(){
    cin>>N;
    for(int p: P){
        if(N%p == 0){
            cout<<N/p<<" "<<N-N/p<<"\n";
            return;
        }
    }
    cout<<1<<" "<<N-1<<"\n";
}
int main(){
    for(int i=2 ; i<MAXN ; i++){
        if(ck[i])continue;
        ck[i] = 1;
        P.push_back(i);
        for(int j=i ; j<N ; j+=i){
            ck[j] = 1;
        }
    }
    int T;
    cin>>T;
    while(T--) solve();
}