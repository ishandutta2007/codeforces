#include<bits/stdc++.h>
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

int T;
char s[19];

signed main() {
    T=read();
    while(T--) {
        scanf("%s",s+1);
        int n=strlen(s+1);
        char lg=127;
        rep(i,1,n) lg=min(lg,s[i]);
        if(n==2) printf("%c\n",s[2]);
        else printf("%c\n",lg);
    }
    return 0;
}