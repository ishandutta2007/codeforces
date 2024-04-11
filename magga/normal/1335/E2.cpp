#include<bits/stdc++.h>
using namespace std;
void pre(){}
int n;
long long int f[201]{0};
long long int arr[200001];
vector<int>foo[201];
long long int opt(int a,int b){
    int u = f[a];
    int ret = u;
    int o1,o2,i1=0,i2=f[a]-1;
    for(int i=1;i<=(f[b]/2);i++){
        o1 = foo[b][i-1];
        o2 = foo[b][f[b]-i];
        while(i1<f[a] && foo[a][i1]<o1){
            i1++;
        }
        while(i2>=0 && foo[a][i2]>o2){
            i2--;
        }
        ret=max(ret,2*i+i2-i1+1);
    }
    return ret;
}
void solve(){
    cin>>n;
    for(int i=0;i<201;i++){f[i]=0;foo[i].clear();}
    for(int i=0;i<n;i++){
        cin>>arr[i];
        f[arr[i]]++;
        foo[arr[i]].push_back(i);
    }
    long long int ans = 0;
    for(int i=1;i<=200;i++){
        for(int j=i+1;j<=200;j++){
            ans=max(ans,opt(i,j));
            ans=max(ans,opt(j,i));
        }
    }
    cout<<ans<<"\n";
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