#include <iostream>

using namespace std;

//b

typedef unsigned long long ll;

ll a[100001];
ll b[100001];


int main(){
    ll n,m;
    cin>>n>>m;
    ll as=0;
    ll bs=0;
    ll am=0;
    ll ami=0;
    ll bm=0;
    ll bmi=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        as+=a[i];
        if (a[i]>am){
            ami=i;
            am=a[i];
        }
    }
    for (int i=0;i<m;i++){
        cin>>b[i];
        bs+=b[i];
        if (b[i]>bm){
            bmi=i;
            bm=b[i];
            bm=b[i];
        }
    }
    ll v=min(as*m, bs*n);
    ll vv=0;
    for (int i=0;i<n;i++){
        if (i!=ami){
            vv+=min(bs, a[i]);
        }
    }
    vv+=bs;
    v=min(v,vv);
    vv=0;
    for (int i=0;i<m;i++){
        if (i!=bmi){
            vv+=min(as, b[i]);
        }
    }
    vv+=as;
    v=min(v,vv);
    cout<<v<<endl;
}