#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,d;cin>>n;
    map<int,int>m;
    for(int i=0;i<n;i++){
        cin>>d;
        m[d]++;
    }
    vector<int>s;
    for(auto i:m){
        s.push_back(i.second);
    }
    int ans = n;
    sort(s.begin(),s.end());
    int u = s[0]+1;
    for(int i=1;i<=u;i++){
        int blop = 0;
        for(auto j:s){
            int ui = (j+i-1)/i;
            if(j%i==0){
                blop+=j/i;
            }else if(ui*i-j<=ui){
                blop+=ui;
            }else{
                blop=n;
                break;
            }
        }
        ans=min(blop,ans);
    }
    cout<<ans<<"\n";
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