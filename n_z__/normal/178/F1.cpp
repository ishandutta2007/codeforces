#include<bits/stdc++.h>
using namespace std;
int f[2001][2001],h[2001],tot,l[2001];
string s[2001];
int dp(int l,int r){
	if(l==r)return 0;
    tot++;
    int q=tot,mid=l+1;
    for(int x=mid;x<=r;x++)
    if(h[x]<h[mid])mid=x;
    int w=dp(l,mid-1),e=dp(mid,r);
    for(int x=0;x<=mid-l;x++)
    for(int y=0;y<=r-mid+1;y++)
    f[q][x+y]=max(f[q][x+y],f[w][x]+f[e][y]+h[mid]*x*y);
    return q;
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int x=1;x<=n;x++)
    cin>>s[x];
	sort(s+1,s+n+1);
    for(int x=1;x<=n;x++)
    {
        l[x]=s[x].length();
        if(x>1){for(int y=0;y<l[x-1]&&y<l[x]&&s[x-1][y]==s[x][y];y++)h[x]=y;h[x]+=(l[x-1]&&l[x]&&s[x-1][0]==s[x][0]);}
    }
    //for(int x=1;x<=n;x++)cout<<h[x]<<' ';cout<<endl;
    cout<<f[dp(1,n)][k];
}