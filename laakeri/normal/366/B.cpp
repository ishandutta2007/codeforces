#include <iostream>

using namespace std;

int t[100001];

int main(){
    int n;
    int k;
    cin>>n>>k;
    int i;
    int ii;
    for (i=0;i<n;i++){
        cin>>t[i];
    }
    long long ms=999999999999;
    int msi;
    for (i=0;i<k;i++){
        long long s=0;
        for (ii=i;ii<n;ii+=k){
            s+=t[ii];
        }
        if (s<ms){
            ms=s;
            msi=i+1;
        }
    }
    cout <<msi<<'\n';
}