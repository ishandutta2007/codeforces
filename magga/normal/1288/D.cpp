#include<bits/stdc++.h>
using namespace std;
long long int n,m,d;
long long int cach[8];
long long int mod = 1000000007;
pair<long long int,long long int>p;
pair<bool,long long int> flag[256];
string s;
void raptor(long long int k,long long int peer){
    if(flag[k].first){
        return;
    }
    flag[k].first=true;
    flag[k].second=peer;
    s = bitset<8>(k).to_string();
    for(long long int i = 0;i<8;i++){
        if(s[i]=='1'){
            raptor(k-cach[7-i],peer);
        }
    }
}
bool check(long long int mid,vector<long long int>arr[]){
    long long int tab[n];
    for(long long int i=0;i<n;i++){
        tab[i]=0;
    }
    for(long long int i=0;i<256;i++){
        flag[i].first=false;
    }
    for(long long int i=0;i<n;i++){
        for(long long int j=0;j<m;j++){
            if(arr[i][j]>=mid){
                tab[i]+=cach[j];
            }
        }
        raptor(tab[i],i);
    }
    long long int ko = cach[m-1]*2-1;
    for(long long int i=0;i<n;i++){
        if(flag[ko-tab[i]].first){
            p.first=flag[ko-tab[i]].second;
            p.second=i;
            return true;
        }
    }
    return false;
}
void solve(){
    ;cin>>n>>m;
    vector<long long int> arr[n];
    long long int plausibe[n*m];
    long long int k =0 ;
    for(long long int i=0;i<n;i++){
        for(long long int j=0;j<m;j++){
            cin>>d;
            plausibe[k]=d;
            k++;
            arr[i].push_back(d);
        }
    }
    sort(plausibe,plausibe+n*m);
    pair<long long int,long long int>ans;
    long long int start = 0 ; long long int end = n*m-1;
    long long int mid ;
    while(start<=end){
        mid = (start+end+1)/2;
        //cout<<plausibe[mid]<<"\n";
        if(check(plausibe[mid],arr)){
            ans =  p;
            //cout<<p.first<<" "<<p.second<<"\n";
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    cout<<ans.first+1<<" "<<ans.second+1<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cach[0]=1;
    cach[1]=2;
    cach[2]=4;
    cach[3]=8;
    cach[4]=16;
    cach[5]=32;
    cach[6]=64;
    cach[7]=128;
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}