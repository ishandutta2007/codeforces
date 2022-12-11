#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
int ck[MAXN], l[MAXN], r[MAXN];
void solve(){
    string S;
    int k;
    cin>>S>>k;
    for(int i=0 ; i<S.size() ; i++){
        ck[i] = 0;
        l[i] = i-1;
        r[i] = i+1;
    }
    char c = '9' + 1;
    int jdx = 0;
    for(int i=0 ; i<=k ; i++){
        if(S[i]!='0' && c > S[i]){
            jdx = i;
            c = S[i];
        }
    }
    k -= jdx;
    for(int i=0 ; i<jdx ; i++){
        ck[i] = 1;
    }
    int idx = jdx + 1;
    l[jdx] = -1;
    while(k){
        if(l[idx]!=-1 && S[l[idx]] > S[idx] && (S[idx]!='0' || l[l[idx]] != -1)){
            ck[l[idx]] = 1;
            r[l[l[idx]]] = idx;
            l[idx] = l[l[idx]];
            k--;
        } else{
            idx = r[idx];
        }
        if(idx == S.size()){
            break;
        }
    }
    idx = S.size() - 1;
    while(k){
        k--;
        ck[idx] = 1;
        idx = l[idx];
    }
    for(int i=0 ; i<S.size() ; i++){
        if(!ck[i]) cout<<S[i];
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
}