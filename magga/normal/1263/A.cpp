#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int ar[3];
    cin>>ar[0]>>ar[1]>>ar[2];
    sort(ar,ar+3);
    if(ar[0]+ar[1]>ar[2]){
        cout<<(ar[0]+ar[1]+ar[2])/2<<"\n";
    }else{
        cout<<ar[0]+ar[1]<<"\n";
    }
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