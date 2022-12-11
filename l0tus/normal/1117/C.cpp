#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e5+5;
long long N,K,A[MAX],S[MAX],sum,cnt,val,res,ans,xval,yval;
char C[MAX];
bool check;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    long long x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2 >> N;
    for(long long i=0; i<N; i++){
        cin >> C[i];
        if(C[i]=='U') yval++;
        if(C[i]=='D') yval--;
        if(C[i]=='R') xval++;
        if(C[i]=='L') xval--;
    }
    ans = 1e18;
    for(long long i=0; i<N; i++){
        long long t = 0, st = 0, en = 1e12;
        while(st<en){
            t = (st+en)/2;
            if((i+N*t)>=(abs(x2-x1-xval*t)+abs(y2-y1-yval*t))) en = t;
            else st = t+1;
        }
        if(C[i]=='U') y1++;
        if(C[i]=='D') y1--;
        if(C[i]=='R') x1++;
        if(C[i]=='L') x1--;
        t = st;
        if(t==1e12) continue;
        ans = min(ans,i+N*t);
    }
    if(ans==1e18) cout << -1;
    else cout << ans;
}