#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    ll e=0;
    ll o=0;
    ll s=0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        if (a%2==0) e++;
        else o++;
        s+=(ll)a;
    }
    int w=0;
    ll vd=(n-k)/2;
    ll vs=(n-k)-vd;
    if ((n-k)%2==0){
        //cout<<(s-((n-k)-e))<<endl;
        if (vs>=o&&(s-o)%2==1){
            w=2;
        }
        else if(vs>=e&&(s-((n-k)-e))%2==1){
            w=2;
        }
        else{
            w=1;
        }
    }
    else{
        if (vd>=o&&(s-o)%2==0){
            w=1;
        }
        else if(vd>=e&&(s-((n-k)-e))%2==0){
            w=1;
        }
        else{
            w=2;
        }
    }
    if (k==n){
        if (s%2==0){
            w=1;
        }
        else{
            w=2;
        }
    }
    if (w==1){
        cout<<"Daenerys"<<endl;
    }
    else{
        cout<<"Stannis"<<endl;
    }
}