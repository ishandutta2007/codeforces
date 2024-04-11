#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int b,w;
    cin>>b>>w;
    int x=min(b,w),y=max(b,w),z=x*3+1;
    if(y>z){
        cout<<"NO\n";
        return;
    }
    else{
        cout<<"YES\n";
        int e=2+(x==b);
        for(int i=e;i<e+(x<<1);i++)cout<<"2 "<<i<<"\n";
        y-=x;
        if(y){
            for(int i=e;i<e+(x<<1);i+=2){
                cout<<"1 "<<i<<"\n";
                y--;
                if(!y)break;
                cout<<"3 "<<i<<"\n";
                y--;
                if(!y)break;
            }
            if(y)cout<<"2 "<<1+(x==b)<<"\n";
        }
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}