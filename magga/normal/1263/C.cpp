#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,d;cin>>n;
    set<long long int>s;
    s.insert(0);
    d=sqrt(n);
    for(long long int i=1;i<=d;i++){
        s.insert(i);
        s.insert(n/i);
    }
    cout<<s.size()<<"\n";
    for(long long int i:s){
        cout<<i<<" ";
    }
    cout<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1 ;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }
}