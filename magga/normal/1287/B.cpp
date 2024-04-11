#include<bits/stdc++.h>
using namespace std;
string alt(string &a,string &b){
    string ret = a;
    for(long long int i=0;i<a.size();i++){
        if(a[i]==b[i]){
            ret[i]=a[i];
        }else{
            if( (a[i]=='T' && b[i]=='E') ||  (a[i]=='E' && b[i]=='T') ){
                ret[i]='S';
            }else if( (a[i]=='S' && b[i]=='E') ||  (a[i]=='E' && b[i]=='S') ){
                ret[i]='T';
            }else if( (a[i]=='S' && b[i]=='T') ||  (a[i]=='T' && b[i]=='S') ){
                ret[i]='E';
            }
        }
    }
    return ret;
}
void solve(){
    long long int n,k;cin>>n>>k;
    string arr[n];  
    map<string,long long int>m;
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        m[arr[i]]++;
    }
    long long int ans = 0;
    for(long long int i=0;i<n;i++){
        for(long long int j=i+1;j<n;j++){
            string p = alt(arr[i],arr[j]);
            if(m[p]!=0){
            if(p!=arr[i] && p!=arr[j]){
                ans += m[p]; 
            }else if(p==arr[i] && p==arr[j]){
                ans += m[p]-2;
            }else if( (p==arr[i] && p!=arr[j] ) || (p!=arr[i] && p==arr[j] )){
                ans += m[p]-1;
            }
            }
        }
    }
    cout<<ans/3<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}