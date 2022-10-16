#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int ar[10] ={119,18,93,91,58,107,111,82,127,123};
int dist(int a,int b){
    int ret = 0;
    if((a|b)!=b){return -1;}
    while(b>0){
        if(b%2==1){
            ret++;
        }
        b/=2;
    }
    while(a>0){
        if(a%2==1){
            ret--;
        }
        a/=2;
    }
    //cout<<ret<<"\n";
    return ret;
}
void solve(){
    long long int n,k;cin>>n>>k;
    pair<int,int> dp[n+1][k+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            dp[i][j]={-1,0};
    int arr[n];
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        arr[i]=stoi(s,0,2);
    }    
    dp[n][0]={0,0};
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=k;j++){
            if(dp[i+1][j].first==-1) continue;
            for(int p=0;p<10;p++){
                int oo = dist(arr[i],ar[p]);
                //cout<<j<<" "<<j+oo<<" "<<"\n";
                if( (j+oo)>k || oo==-1){
                    continue;
                }
                if(p>dp[i][j+oo].first){
                    dp[i][j+oo]={p,j};
                }
            }
        }
    }
    if(dp[0][k].first==-1){
        cout<<-1<<"\n";
        return;
    }
    int cur = k;
    for(int i=0;i<n;i++){
        cout<<dp[i][cur].first;
        cur=dp[i][cur].second;
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