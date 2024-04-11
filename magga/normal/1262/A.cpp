#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,a,b;cin>>n;
    long long int min = 10000000000;
    long long int max = -10000000000;
    //long long int a[n];
    //long long int b[n];
    bool flag= false;
    for(long long int i=0;i<n;i++){
        cin>>a>>b;
        if(max<=a && min>=b){
            max = a;
            min = b;
            flag = true;
        }else if(min>b){
            min = b;
            flag = false;
        }else if(max<a){
            max=a;
            flag = false;
        }
        //cout<<a<<" "<<b<<" "<<max<<" "<<min<<"\n";
    }
    long long int pop= max-min;
    long long int hop =0;
    if(flag){
        cout<<0<<"\n";
    }else if(max-min>0){
        cout<<pop<<"\n";
    }else{
        cout<<hop<<"\n";
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