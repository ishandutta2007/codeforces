#include<bits/stdc++.h>
using namespace std;
int a[1001],b[1001];
int main(){
    int n;
    cin>>n;
    for(int x=1;x<=n;x++)
    cin>>a[x]>>b[x];
    while(1){
        int s=0;
        for(int x=1;x<=n;x++)
        s+=((a[x]+b[x])&1);
        if(s>0&&s<n)
        {
            cout<<s<<endl;
            for(int x=1;x<=n;x++)
            if(((a[x]+b[x])&1))cout<<x<<' ';
            break;
        }
        for(int x=1,t;x<=n;x++)
        t=b[x],b[x]=(b[x]+a[x])>>1,a[x]=(a[x]-t)>>1;
    }
}