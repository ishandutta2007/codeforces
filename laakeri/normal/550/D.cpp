#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if (n%2==0){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        vector<pair<int, int> > es;
        for (int i=2;i<=n;i++){
            es.push_back({1, i});
        }
        for (int i=n+1;i<=n+n-1;i++){
            for (int ii=2;ii<=n;ii++){
                es.push_back({ii, i});
            }
            if ((i-(n+1))%2==0) es.push_back({i, i+1});
        }
        int ne=n*2-1;
        es.push_back({1, ne+1});
        for (int i=2;i<=n;i++){
            es.push_back({ne+1, ne+i});
        }
        for (int i=n+1;i<=n+n-1;i++){
            for (int ii=2;ii<=n;ii++){
                es.push_back({ne+ii, ne+i});
            }
            if ((i-(n+1))%2==0) es.push_back({ne+i, ne+i+1});
        }
        cout<<ne+n+n-1<<" "<<es.size()<<endl;
        for (auto e:es){
            cout<<e.F<<" "<<e.S<<'\n';
        }
    }
}