#include <iostream>

using namespace std;

typedef long long ll;

ll as[100001];

int main(){
    int n;
    cin>>n;
    ll r=0;
    ll y=0;
    for (int i=0;i<n;i++){
        cin>>as[i];
        r=max(r,as[i]);
        y+=as[i];
    }
    ll s=0;
    for (int i=0;i<n;i++){
        s+=r-as[i];
    }
    ll sn=y/(n-1);
    if (y%(n-1)) sn++;

    if (sn>s){
        r+=(sn-s)/n;
        if ((sn-s)%n) r++;
    }
    cout<<r<<endl;
}