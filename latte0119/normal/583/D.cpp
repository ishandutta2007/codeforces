#include<bits/stdc++.h>
using namespace std;

int N,T;
int A[20000];
int cnt[100];
vector<int>press;

int dp[20010];
int f(int l,int u){
    vector<int>a;
    for(int i=0;i<N;i++){
        if(l<=A[i]&&A[i]<=u)a.push_back(A[i]);
    }
    fill_n(dp,N+2,1001001001);
    dp[0]=0;
    for(int i=0;i<a.size();i++){
        int p=upper_bound(dp,dp+N+2,a[i])-dp;
        dp[p]=a[i];
    }

    return lower_bound(dp,dp+N+2,1001001001)-dp-1;
}

int main(){
    cin>>N>>T;
    for(int i=0;i<N;i++)cin>>A[i],press.push_back(A[i]);
    sort(press.begin(),press.end());
    press.erase(unique(press.begin(),press.end()),press.end());
    for(int i=0;i<N;i++){
        A[i]=lower_bound(press.begin(),press.end(),A[i])-press.begin();
        cnt[A[i]]++;
    }
    if(T<=200){
        for(int i=0;i<N*T;i++)A[i]=A[i%N];
        N*=T;
        cout<<f(0,press.size())<<endl;
        return 0;
    }

    for(int i=0;i<N*100;i++)A[i]=A[i%N];
    N*=100;
    int ans=0;
    for(int i=0;i<press.size();i++){
        ans=max(ans,f(0,i)+f(i,press.size())+cnt[i]*(T-200));
    }
    cout<<ans<<endl;

    return 0;
}