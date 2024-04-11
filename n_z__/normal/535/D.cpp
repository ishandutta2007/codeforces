#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int qp(int A,int P,int MOD)
{
    register int Return=1;
    while(P)
    {
        if(P&1)
        {
            Return*=A;
            Return%=MOD;
        }
        A*=A;
        A%=MOD;
        P>>=1;
    }
    return Return%MOD;
}
signed main(){
    int n,m;
    string p;
    cin>>n>>m>>p;
    int e=-1;
    while(m--){
        int y;
        cin>>y;
        if(y-e>=p.length()||e==-1)n-=p.length();
        else if(p[y-e]!=p[0])return puts("0")*0;
        else n-=y-e;
        e=y;
    }
    cout<<qp(26,n,(int)(1e9+7));
}