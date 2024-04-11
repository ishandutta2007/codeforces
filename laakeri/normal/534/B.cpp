#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int lol[1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int v1,v2;
    cin>>v1>>v2;
    int t,d;
    cin>>t>>d;
    int mt=v1;
    for (int i=0;i<t;i++){
        lol[i]=mt;
        mt+=d;
    }
    mt=v2;
    for (int i=t-1;i>=0;i--){
        lol[i]=min(lol[i], mt);
        mt+=d;
    }
    ll asd=0;
    for (int i=0;i<t;i++){
        asd+=(ll)lol[i];
    }
    cout<<asd<<endl;
}