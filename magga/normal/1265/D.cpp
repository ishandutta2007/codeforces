#include<bits/stdc++.h>
using namespace std;
long long int arr[200000]{0};
long long int p=1;
bool process(long long int b,long long int &l,long long int &u){
    if(arr[p-1]==b){
      //  cout<<"Yay"<<arr[p-1]<<" "<<b<<"\n";;
        if(u!=0){
            arr[p]=b+1;
            u--;
            //cout<<arr[p];
            p++;
            return true;
        }else{
            return false;
        }
    }else if(arr[p-1]==b+1){
        if(l!=0){
        //     cout<<"Gay"<<arr[p-1]<<" "<<b<<"\n";;
            arr[p]=b;
            l--;
            //cout<<arr[p];
            p++;
            return true;
        }else{
            return false;
        }
    }
    return false;
}
bool conc(long long int a,long long int b,long long int c,long long int d){
    p=1;
    //bool b =false;
    arr[0]=4;
    if(d!=0){
        arr[0]=4;d--;
    }else if(c!=0){
        arr[0]=3;c--;
    }else if(b!=0){
        arr[0]=2;b--;
    }else if(a!=0){
        arr[0]=1;a--;
    }
    long long int n;
    n=a+b+c+d;
    long long int i=0;
    long long int ans=3;
    for(;i<n;i++){
        if(!process(ans,c,d)){
            ans--;
            //i--;
            break;
        }else{
            
        }
    }
    for(;i<n;i++){
        if(!process(ans,b,c)){
            ans--;
            //i--;
            break;
        }else{
        }
    }
    for(;i<n;i++){
        if(!process(ans,a,b)){
            ans--;
            //cout<<"\n";
            return false;
        }else{
            //return false;
        }
    }
    //cout<<"\n";
    if(a==0){
        return true;
    }
    return false;
}
bool conc1(long long int a,long long int b,long long int c,long long int d){
    p=1;
    if(d!=0){
        arr[0]=3;c--;
        if(c==-1){
            return false;
        }
    }else if(c!=0){
        arr[0]=2;b--;
        if(b==-1){
            return false;
        }
    }else if(b!=0){
        arr[0]=1;a--;
        if(a==-1){
            return false;
        }
    }else if(a!=0){
        arr[0]=0;return false;
    }
    //c--;
    long long int n;
    n=a+b+c+d;
    long long int i=0;
    long long int ans=3;
    for(;i<n;i++){
        if(!process(ans,c,d)){
            ans--;
            //i--;
            break;
        }
    }
    for(;i<n;i++){
        if(!process(ans,b,c)){
            ans--;
            //i--;
            break;
        }else{
        }
    }
    for(;i<n;i++){
        if(!process(ans,a,b)){
            ans--;
            //i--;
      //      cout<<"\n";
            return false;
        }else{
            //return false;
        }
    }
    //cout<<"\n";
    if(a==0){
        return true;
    }
    return false;
}
void solve(){
    long long int n;//cin>>n;
    //bool flag = false;
    long long int a,b,c,d;cin>>a>>b>>c>>d;
    n=a+b+c+d;
    if(conc(a,b,c,d)){
        cout<<"YES"<<"\n";
        for(long long int i=0;i<n;i++){
            cout<<arr[i]-1<<" ";
        }
        cout<<"\n";
    }else if(conc1(a,b,c,d)){
       cout<<"YES"<<"\n";
        for(long long int i=0;i<n;i++){
            cout<<arr[i]-1<<" ";
        }
        cout<<"\n"; 
    }else{
        cout<<"NO"<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
   // cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}