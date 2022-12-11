#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll x,y,ax,ay,bx,by,xs,ys,t,sz,X[200],Y[200],D[200][200],val,cur,cnt,ans;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> X[0] >> Y[0] >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    for(int i=1; i<200; i++){
        X[i] = ax*X[i-1]+bx;
        Y[i] = ay*Y[i-1]+by;
        //cout << X[i] << ' ' << Y[i] << '\n';
        sz = i;
        if(X[i]>1e16||Y[i]>1e16) break;
    }
    for(int i=0; i<=sz; i++){
        for(int j=i+1; j<=sz; j++){
            D[i][j] = D[j][i] = X[j]-X[i]+Y[j]-Y[i];
        }
    }
    for(int i=0; i<=sz; i++){
        val = t-abs(xs-X[i])-abs(ys-Y[i]);
        if(val<0) continue;
        cur = i;
        cnt = 1;
        while(cur>0&&val>=D[cur][cur-1]){
            cnt++;
            val-=D[cur][cur-1];
            cur--;
        }
        //cout << i << ' ' << cnt << '\n';
        ans = max(ans,cnt);
    }
    for(int i=0; i<=sz; i++){
        val = t-abs(xs-X[i])-abs(ys-Y[i]);
        if(val<0) continue;
        cur = i;
        cnt = 1;
        while(cur<sz&&val>=D[cur][cur+1]){
            cnt++;
            val-=D[cur][cur+1];
            cur++;
        }
        ans = max(ans,cnt);
    }
    cout << ans;
}