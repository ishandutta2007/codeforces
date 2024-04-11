#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int d[101010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v;
    for (int i=2;i<=n;i++){
        if (d[i]==0){
            int k=i;
            while (k<=n){
                v.push_back(k);
                k*=i;
            }
            for (int j=i;j<=n;j+=i){
                d[j]=1;
            }
        }
    }
    cout<<v.size()<<endl;
    for (int vv:v){
        cout<<vv<<" ";
    }
}