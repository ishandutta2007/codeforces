#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=1e5+9;
char s[N],t[N];
int n;

signed main() {
    int T=read();
    while(T--) {
        scanf("%lld%s%s",&n,s+1,t+1);
        int ans1=0,ans2=0;
        int t1=0,t2=0;
        rep(i,1,n) if(s[i]!=t[i]) {
            ans1++;
            if(s[i]=='0') t1++;
            else t2++;
        }
        if(ans1%2!=0||t1!=t2) ans1=n+1;
        t1=0, t2=0;
        rep(i,1,n) if(s[i]==t[i]) {
            ans2++;
            if(s[i]=='0') t1++;
            else t2++;
        }
        if(ans2%2==0||t2-t1!=1) ans2=n+1;
        int ans=min(ans1,ans2);
        if(ans==n+1) puts("-1");
        else printf("%lld\n",ans);
    }
    return 0;
}