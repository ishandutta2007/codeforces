#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,k;cin>>n>>k;
    long long int ns = n;
    long long int ar[n];
    for(int i=0;i<n;i++) cin>>ar[i];
    pair<long long int,long long int>arr[n/2];
    pair<long long int,long long int>brr[n/2];
    map<long long int,long long int>m;
    for(int i=0;i<n/2;i++){
        arr[i].first=min(ar[i],ar[n-1-i]);
        arr[i].second=max(ar[i],ar[n-1-i]);
        m[arr[i].first+arr[i].second]++;
        brr[i].first=arr[i].second;
        brr[i].second=brr[i].first;
    }
    sort(arr,arr+n/2);
    sort(brr,brr+n/2);
    int start,end,mid,ans,ans2=0;
    for(int i=2;i<=2*k;i++){
        ans2=0;
        start = 0 ;end = n/2-1;ans = 0;
        while(start<=end){
            mid=(start+end+1)/2;
            if(arr[mid].first<i){
                start=mid+1;
            }else{
                ans=n/2-mid;
                end=mid-1;
            }
        }
        ans2+=ans;
        start = 0 ;end = n/2-1;ans = 0;
        while(start<=end){
            mid=(start+end+1)/2;
            if(k+brr[mid].first<i){
                start=mid+1;
                ans=mid+1;
            }else{
                end=mid-1;
            }
        }
        ans2+=ans;
        ans2+=n/2;
        ans2-=m[i];
        ns=min((long long int)ns,(long long int)ans2);
    }
    cout<<ns<<"\n";
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