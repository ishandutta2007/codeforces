#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define ll long long

char c1[111111];
int z[222222],d[111111],sb[111111],t[111111],q[111111];

const int mod=1e9+7;

int main(){
#pragma comment(linker, "/STACK:268435456")
#ifdef HOME
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string s,c,tmp;
    vector<int> tt;
    int i,j,l=0,r=0,len,x,pos,nxt,tlen,clen;
    gets(c1);
    s=c1;
    gets(c1);
    c=c1;
    For(i,222222) z[i]=0;
    z[0]=0;
    tmp=c;
    tmp+="#"+s;
    clen=c.length();
    len=tmp.length();
    z[0]=0;
    for(i=1;i<len;i++){
        if(i<r){
            z[i]=min(z[i-l],r-i);
        }
        while(z[i]+i<len&&tmp[z[i]]==tmp[z[i]+i]) z[i]++;
        if(i+z[i]>=r){
            r=i+z[i];
            l=i;
        }
        if(z[i]==clen) tt.pb(i);
    }
    tlen=tt.size();
    For(i,111111) d[i]=sb[i]=q[i]=0;
    pos=-1;
    len=s.length();
    For(i,len){
        if(pos+1<tlen&&tt[pos+1]-2<=i){
            pos++;
        }
        if(pos==-1){
            t[i]=-1;
        }
        else t[i]=tt[pos]-clen-1;
    }
    int K=0;
    For(i,len){
        if(t[i]!=-1){
            K%=mod;
            if(t[i-1]!=-1&&t[i]!=t[i-1]) FOR(j,t[i-1],t[i]){
                K+=sb[j];
                K%=mod;
            }
            d[i]=K+1+t[i];
            d[i]%=mod;
            if(i!=0) sb[i]=sb[i-1];
            sb[i]+=d[i];
            sb[i]%=mod;
        }
    }
    int ans=0;
    For(i,len){
        ans+=d[i];
        ans%=mod;
    }
    printf("%d",ans);
    return 0;
}