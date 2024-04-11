#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

vector<int> e[101010];

int l[101010];
int d[101010];


int lol[222];
int getp(int x){
    int r=0;
    for (int i=0;i<222;i++){
        if (lol[i]<=x){
            r+=lol[i]*i;
            x-=lol[i];
        }
        else if(x>0){
            r+=x*i;
            x=0;
        }
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>l[i];
    }
    for (int i=0;i<n;i++){
        cin>>d[i];
    }
    for (int i=0;i<n;i++){
        e[l[i]].push_back(d[i]);
        lol[d[i]]++;
    }
    int bv=1e9;
    int rp=0;
    int rm=0;
    for (int i=100000;i>=0;i--){
        if (e[i].size()>0){
            for (int a:e[i]){
                lol[a]--;
            }
            int le=(n-rm-e[i].size());
            int ne=le-e[i].size()+1;
            bv=min(bv, rp+getp(ne));
            for (int a:e[i]){
                rp+=a;
                rm++;
            }
        }
    }
    cout<<bv<<endl;
}