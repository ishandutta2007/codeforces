#include <bits/stdc++.h>
using namespace std;
void solve(){
    cout<<"a"<<"\n";
    cout.flush();
    long long int i = 0;
    long long int d = 0;
    cin>>d;
    if(d==0){
        return;
    }
    long long int n = d+1;
    long long int arr[n+1];
    string ret = "";
    string bkup = "";
    for(long long int j=0;j<n;j++){
        ret+="a";
    }
    for(long long int j=0;j<n-1;j++){
        bkup+="b";
    }
    if(n!=301){
        cout<<ret<<"\n";
        cout.flush();
        cin>>arr[i];
    }else{
         cout<<bkup<<"\n";
        cout.flush();
        return;
    }    
    if(arr[i]==0){
        return;
    }
    if(arr[i]==n){
        cout<<bkup<<"\n";
        cout.flush();
        return;
    }
    i++;
    for(long long int j=0;j<n;j++){
        if( j ==n-1 && ret == bkup+"a"){
            cout<<bkup<<"\n";
            cout.flush();
            return;
        }
        ret[j]='b';
        cout<<ret<<"\n";
        cout.flush();
        cin>>arr[i];
        if(arr[i]==0){
            return;
        }else{
            if(arr[i]>=arr[i-1]){
                ret[j]='a';
            }
            i++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}