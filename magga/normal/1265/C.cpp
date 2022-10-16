#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;
    cin>>n;
    long long int arr[n];
    long long int magic = -1;
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        if(i!=0 && arr[i]!=arr[i-1] && i<=n/2){
            magic=i;
        }
    }
    magic--;
    if(magic<0){
        cout<<0<<" "<<0<<" "<<0<<"\n";
        return;
    }
    long long int g=0;
    long long int s=0;
    long long int b=0;
    long long int i =0;
    long long int loo=arr[0];
    while(i<=magic){
        if(arr[i]==loo){
            g++;
        }else{
            loo=arr[i];
            break;
        }
        i++;
    }
    while(i<=magic){
        if(arr[i]==loo){
            s++;
        }else if(s>g){
            loo=arr[i];
            break;
        }else{
            loo=arr[i];
            s++;
        }
        i++;
    }
    b = magic+1-g-s;
    if(g<b && g<s){
        cout<<g<<" "<<s<<" "<<b<<"\n";
    }else{
        cout<<0<<" "<<0<<" "<<0<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}