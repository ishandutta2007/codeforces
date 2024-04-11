#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int arr[n];
    int index[n+1];
    for(int i=0;i<n;i++){cin>>arr[i];index[arr[i]]=i;}
    int lst = n-1;
    int j = 1;
    for(int i=1;i<=n;i++){
        if(index[i]==lst){
            lst--;
            continue;
        }
        int p = i;
        for(int j = index[i]+1 ; j <= lst;j++){
            //cout<<j<<" ";
            if(arr[j]-arr[j-1]!=1){
                cout<<"No"<<"\n";
                return;
            }
            i++;
        }
        lst=index[p]-1;
    }
    cout<<"Yes"<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
	//cout<<"Case #"<<i+1<<": ";
       	solve();
    }   
}