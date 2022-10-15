#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a,b;
    cin>>a>>b;
    int divi=b/a;
    int mod=b%a;
    int ans=0,cnt=divi;
    for(int i=0;i<a;i++){
        if(mod>0){
            cnt++;
            mod--;
        }
        ans+=pow(cnt,2);
        cnt=divi;
    }
    cout<<ans<<"\n";
}
int main(){
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}