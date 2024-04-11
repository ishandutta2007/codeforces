#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int n,k;
void query(int p){
    cout<<'?'<<" ";
    for(long long int i=1;i<=k+1;i++){
        if(p!=i){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
    cout.flush();
}
void solve(){
    cin>>n>>k;
    query(k+1);
    int ref,aps;cin>>aps>>ref;
    int d,a,m,m1;
    query(aps);
    cin>>a>>d;
    int ans = 1;
    if(d>ref){ 
        for(int i=1;i<=k;i++){
            if(i!=aps){
                query(i);
                cin>>m1>>m;
                if(m!=ref){
                    ans++;
                }
            }
        }
    }else{
        for(int i=1;i<=k;i++){
            if(i!=aps){
                query(i);
                cin>>m1>>m;
                if(m==ref){
                    ans++;
                }
            }
        }
    }
    cout<<'!'<<" "<<ans<<"\n";
    cout.flush();
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