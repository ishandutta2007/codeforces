#include <bits/stdc++.h>
using namespace std;
void eat(){
    int n;string a,b;
    cin>>n>>a>>b;
    a="_"+a;
    b="_"+b;
    vector<pair<int,int> > ans;
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]){
            bool ok=0;
            for(int j=i+1;j<=n;j++){
                if(b[i]==b[j]){
                    ans.push_back({i,j});
                    swap(a[i],b[j]);
                    ok=1;
                    break;
                }
            }
            if(!ok){
                for(int j=i+1;j<=n;j++){
                    if(a[j]==b[i]){
                        ans.push_back({j,n});
                        ans.push_back({i,n});
                        swap(a[j],b[n]);
                        swap(a[i],b[n]);
                        ok=1;
                        break;
                    }
                }
            }
            if(!ok){
                cout<<"No\n";
                return;
            }
        }
    }
    cout<<"Yes\n"<<ans.size()<<"\n";
    for(auto i:ans)cout<<i.first<<" "<<i.second<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)eat();
}