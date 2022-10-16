#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,a,d;cin>>n;
    bool flag[n];
    bool marr[n];
    for(long long int i=0;i<n;i++){ flag[i]=0;marr[i]=0;}
    vector<long long int>arr[n];
    for(long long int i=0;i<n;i++){
        cin>>a;
        for(long long int j=0;j<a;j++){
            cin>>d;d--;
            arr[i].push_back(d);
        }
    }
    long long int unmarried=-1;
    for(long long int i=0;i<n;i++){
        for(auto j:arr[i]){
            if(flag[j]){
                continue;
            }else{
                flag[j]=1;
                marr[i]=1;
                break;
            }
        }
        if(!marr[i]){
            unmarried=i;
        }
    }
    if(unmarried==-1)
        cout<<"OPTIMAL"<<"\n";
    else{
        cout<<"IMPROVE"<<"\n";
        long long int b ;
        for(long long int i=0;i<n;i++){
            if(!flag[i]){
                b=i;
                break;
            }
        }
        cout<<unmarried+1<<" "<<b+1<<"\n";
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