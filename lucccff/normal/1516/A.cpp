#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    int a[110];
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>k;
        for(j=0;j<n;j++) cin>>a[j];
        l=0;
        for(j=0;j<k;j++) {
            while((a[l]==0)&&(l<n)) l++;
            if (l>=n-1) break;
            a[l]--;
            a[n-1]++;
        }
        for(j=0;j<n;j++) cout<<a[j]<<' ';
        cout<<endl;
    }
    return 0;
}