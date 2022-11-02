#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int a[101010];
int u[101010];

vector<vector<int> > lol[101010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int c1=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]==i){
            c1=i;
        }
    }
    if (c1>0){
        cout<<"YES"<<endl;
        for (int i=1;i<=n;i++){
            if (i!=c1){
                cout<<i<<" "<<c1<<'\n';
            }
        }
        return 0;
    }
    for (int i=1;i<=n;i++){
        vector<int> t;
        int x=i;
        while (!u[x]){
            t.push_back(x);
            u[x]=1;
            x=a[x];
        }
        if (t.size()%2!=0){
            cout<<"NO"<<endl;
            return 0;
        }
        if (t.size()>0){
            lol[t.size()].push_back(t);
        }
    }
    if (lol[2].size()==0){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    int v1=lol[2][0][0];
    int v2=lol[2][0][1];
    cout<<v1<<" "<<v2<<'\n';
    for (int i=1;i<(int)lol[2].size();i++){
        cout<<lol[2][i][0]<<" "<<v1<<'\n';
        cout<<lol[2][i][1]<<" "<<v2<<'\n';
    }
    for (int i=4;i<=n+100;i+=2){
        for (auto&t:lol[i]){
            for (int j=0;j<(int)t.size();j++){
                if (j%2==0){
                    cout<<t[j]<<" "<<v1<<'\n';
                }
                else{
                    cout<<t[j]<<" "<<v2<<'\n';
                }
            }
        }
    }
}