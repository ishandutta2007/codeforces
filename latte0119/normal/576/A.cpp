#include<bits/stdc++.h>
using namespace std;

bool f[2000];

void prime(){
    fill_n(f,2000,true);
    f[0]=f[1]=false;
    for(int i=2;i<=1000;i++){
        if(!f[i])continue;
        for(int j=2;i*j<=1000;j++)f[i*j]=false;
    }
}

int main(){
    cin.tie();
    ios_base::sync_with_stdio(false);

    prime();

    int n;
    cin>>n;
    vector<int>res;
    for(int i=2;i<=n;i++){
        if(!f[i])continue;

        int d=i;
        while(d<=n){
            res.push_back(d);
            d*=i;
        }
    }

    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}