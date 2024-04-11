#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int has[202020];
vector<int> lol[202020];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        has[a]++;
        lol[a].push_back(i+1);
    }
    vector<int> v;
    int f=0;
    int t=0;
    while (f<n){
        while (t>2&&has[t]==0){
            t-=3;
        }
        if (t<3&&has[t]==0){
            cout<<"Impossible"<<endl;
            return 0;
        }
        has[t]--;
        v.push_back(lol[t].back());
        lol[t].pop_back();
        f++;
        t++;
    }
    cout<<"Possible"<<endl;
    for (int a:v){
        cout<<a<<" ";
    }
}