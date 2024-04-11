#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int inf = -1e10;
void solve(){
    set<pair<int,int>>se;
    long long int n,d;cin>>n;
    pair<int,int>arr[n][n];
    for(long long int i=0;i<n;i++){
        for(long long int j=0;j<n;j++){
            cin>>d;
            arr[i][j]={0,0};
            if(d==0){
                se.insert({i,j});
                arr[i][j]={inf,inf};
                continue;
            }
            while(d%2==0){
                arr[i][j].first++;
                d/=2;
            }
            while(d%5==0){
                arr[i][j].second++;
                d/=5;
            }
        }
    }
    pair<long long int,char> dp1[n][n];
    pair<long long int,char> dp2[n][n];
    for(long long int i=0;i<n;i++){
        for(long long int j=0;j<n;j++){
            if(j==0 && i==0){
                dp1[0][0]={arr[0][0].first,'A'};
                dp2[0][0]={arr[0][0].second,'A'};
            }else if(i==0){
                dp1[0][j]={arr[0][j].first+dp1[0][j-1].first,'R'};
                dp2[0][j]={arr[0][j].second+dp2[0][j-1].first,'R'};
            }else if(j==0){
                dp1[i][0]={arr[i][0].first+dp1[i-1][0].first,'D'};
                dp2[i][0]={arr[i][0].second+dp2[i-1][0].first,'D'};
            }else{
                if(dp1[i-1][j].first<dp1[i][j-1].first){
                    dp1[i][j]={arr[i][j].first+dp1[i-1][j].first,'D'};
                }else{
                    dp1[i][j]={arr[i][j].first+dp1[i][j-1].first,'R'};
                }
                if(dp2[i-1][j].first<dp2[i][j-1].first){
                    dp2[i][j]={arr[i][j].second+dp2[i-1][j].first,'D'};
                }else{
                    dp2[i][j]={arr[i][j].second+dp2[i][j-1].first,'R'};
                }
            }
        }
    }
    long long int ans = min(dp1[n-1][n-1].first,dp2[n-1][n-1].first);
    char vol[n][n];
    if(ans==dp1[n-1][n-1].first){
        for(long long int i=0;i<n;i++){
            for(long long int j=0;j<n;j++){
                vol[i][j]=dp1[i][j].second;
            }
        }
    }else{
        for(long long int i=0;i<n;i++){
            for(long long int j=0;j<n;j++){
                vol[i][j]=dp2[i][j].second;
            }
        }
    }
    long long int i=n-1,j=n-1;
    string s = "";
    while(i!=0 || j!=0){
        s+=vol[i][j];
        if(vol[i][j]=='R'){
            j--;
        }else{
            i--;
        }
    }
    pair<long long int,string>an;
    if(ans>=0)
    an.first=ans;
    else
    an.first=1;;

    an.second=s;
    for(auto i:se){
        arr[i.first][i.second]={1,1};
    }
    for(long long int i=0;i<n;i++){
        for(long long int j=0;j<n;j++){
            if(j==0 && i==0){
                dp1[0][0]={arr[0][0].first,'A'};
                dp2[0][0]={arr[0][0].second,'A'};
            }else if(i==0){
                dp1[0][j]={arr[0][j].first+dp1[0][j-1].first,'R'};
                dp2[0][j]={arr[0][j].second+dp2[0][j-1].first,'R'};
            }else if(j==0){
                dp1[i][0]={arr[i][0].first+dp1[i-1][0].first,'D'};
                dp2[i][0]={arr[i][0].second+dp2[i-1][0].first,'D'};
            }else{
                if(dp1[i-1][j].first<dp1[i][j-1].first){
                    dp1[i][j]={arr[i][j].first+dp1[i-1][j].first,'D'};
                }else{
                    dp1[i][j]={arr[i][j].first+dp1[i][j-1].first,'R'};
                }
                if(dp2[i-1][j].first<dp2[i][j-1].first){
                    dp2[i][j]={arr[i][j].second+dp2[i-1][j].first,'D'};
                }else{
                    dp2[i][j]={arr[i][j].second+dp2[i][j-1].first,'R'};
                }
            }
        }
    }
    ans = min(dp1[n-1][n-1].first,dp2[n-1][n-1].first);
    if(ans==dp1[n-1][n-1].first){
        for(long long int i=0;i<n;i++){
            for(long long int j=0;j<n;j++){
                vol[i][j]=dp1[i][j].second;
            }
        }
    }else{
        for(long long int i=0;i<n;i++){
            for(long long int j=0;j<n;j++){
                vol[i][j]=dp2[i][j].second;
            }
        }
    }
    i=n-1,j=n-1;
    s = "";
    while(i!=0 || j!=0){
        s+=vol[i][j];
        if(vol[i][j]=='R'){
            j--;
        }else{
            i--;
        }
    }
    if(ans==0){
        an.first=0;
        an.second=s;
    }
    cout<<an.first<<"\n";
    s=an.second;
    for(long long int i=0;i<s.size();i++){
        cout<<s[s.size()-1-i];
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}