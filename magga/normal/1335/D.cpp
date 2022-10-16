#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    char arr[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(arr[i][j]=='1'){
                cout<<2;
            }else{
                cout<<arr[i][j];
            }
        }
        cout<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}