#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e5+5,lg=18;
int n,rk[lg][mxN],ord[mxN],lcp[mxN],z;
string s;
bool cmp(int x,int y){
    if(rk[z-1][x]!=rk[z-1][y])return rk[z-1][x]<rk[z-1][y];
    if(max(x,y)+(1<<(z-1))>n)return x>y;
    return rk[z-1][x+(1<<(z-1))]<rk[z-1][y+(1<<(z-1))];
}
void build(){
    for(int i=1;i<=n;i++){
        rk[0][i]=s[i];
        ord[i]=i;
    }
    for(z=1;z<lg;z++){
        sort(ord+1,ord+n+1,cmp);
        rk[z][ord[1]]=1;
        for(int i=2;i<=n;i++)rk[z][ord[i]]=rk[z][ord[i-1]]+cmp(ord[i-1],ord[i]);
    }
}
int qry_lcp(int x,int y){
    int ans=0;
    for(int i=lg-1;i>=0&&x<=n&&y<=n;i--){
        if(rk[i][x]==rk[i][y]){
            x+=(1<<i);
            y+=(1<<i);
            ans+=(1<<i);
        }
    }
    return ans;
}
signed main(){
    int k;
    cin>>s>>k;
    n=s.length();
    s="_"+s;
    if(k>n*(n+1)/2){
        cout<<"No such line.\n";
        return 0;
    }
    build();
    for(int i=1;i<n;i++)lcp[i]=qry_lcp(ord[i],ord[i+1]);
    for(int i=1;i<=n;i++){
        for(int j=lcp[i-1]+1;j<=n-ord[i]+1;j++){
            int l=i,r=n+1;
            while(l+1<r){
                int mid=(l+r)>>1;
                if(qry_lcp(ord[i],ord[mid])>=j)l=mid;
                else r=mid;
            }
            k-=r-i;
            if(k<=0){
                cout<<s.substr(ord[i],j)<<"\n";
                return 0;
            }
        }
    }
}