#include <bits/stdc++.h>
using namespace std;

void gui(long long k, long long d, long long n) {
    long long l,x,y,z,i,j;
    l=1;
    x=1;
    while (k>=x) {
        x<<=1;
        l++;
    }
    for(i=d;i<=n-l;i++) {
        cout<<i<<' ';
    }
    y=z=n-l+1;
    x=(x+1)>>1;
    while(k>=x) {
        k-=x;
        x=(x+1)>>1;
        z++;
    }
    for(i=z;i>=y;i--) {
        cout<<i<<' ';
    }
    if (z<n) gui(k,z+1,n);
}


int main(){
    long long i,j,k,l,m,n,t,x,y,z;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>k;
        l=1;
        x=1;
        while (k>x) {
            x<<=1;
            l++;
        }
        if (l>n) {
            cout<<-1<<endl;
            continue;
        }
        k--;
        gui(k,1,n);
        cout<<endl;
    }
    return 0;
}