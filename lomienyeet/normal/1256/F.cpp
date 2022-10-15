#include <bits/stdc++.h>
using namespace std;
const int mxN=26+5;
int bit[mxN];
void upd(int x,int v){
    for(;x<mxN;x+=x&-x)bit[x]+=v;
}
int qry(int x){
    int ans=0;
    for(;x;x-=x&-x)ans+=bit[x];
    return ans;
}
void eat(){
    int n;string a,b;
    cin>>n>>a>>b;
    string c=a,d=b;
    sort(c.begin(),c.end());
    sort(d.begin(),d.end());
    if(c!=d){
        cout<<"NO\n";
        return;
    }
    for(int i=0;i<n-1;i++){
        if(c[i]==c[i+1]){
            cout<<"YES\n";
            return;
        }
    }
    int fa[n],fb[n];
    for(int i=0;i<n;i++){
        fa[i]=a[i]-'a'+1;
        fb[i]=b[i]-'a'+1;
    }
    int z=0,w=0;
    memset(bit,0,sizeof bit);
    for(int i=0;i<n;i++){
        z+=i-qry(fa[i]);
        upd(fa[i],1);
    }
    memset(bit,0,sizeof bit);
    for(int i=0;i<n;i++){
        w+=i-qry(fb[i]);
        upd(fb[i],1);
    }
    z&=1;
    w&=1;
    cout<<(z==w?"YES\n":"NO\n");
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}