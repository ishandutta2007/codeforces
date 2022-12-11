#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 1e6+5;
ll N,M,A[MN],B[MN],st,cur,S[MN],P,K,num,cnt,ans,out=1e18;
bool ch[MN];
void act()
{
    st = cur = 1;
    ans = 0;
    for(int i=1; i<=N; i++){
        A[i]=B[i]%P;
        S[i]=S[i-1]+A[i];
    }
    M = S[N]/P;
    for(int t=0; t<M; t++){
        num = cnt = 0;
        while(st<N&&num+A[st]<=P){
            cnt += (ll)abs(st-cur)*A[st];
            num += A[st];
            st++;
        }
        cnt += abs(st-cur)*(P-num);
        A[st] -= P-num;
        while(cur<N&&2*max(0ll,S[cur]-t*P)-P<0){
            cnt += 2*max(0ll,S[cur]-t*P)-P;
            cur++;
        }
        ans += cnt;
        cur++;
    }
    out = min(out,ans);
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> B[i];
        K += B[i];
    }
    if(K==1){
        cout << -1;
        return 0;
    }
    for(int i=2; i<=1000000; i++){
        if(ch[i]) continue;
        if(K%i==0){
            P = i;
            act();
        }
        for(int j=2; i*j<=1000000; j++) ch[i*j]=1;
    }
    for(int i=2; i<=1000000; i++){
        if(ch[i]) continue;
        while(K%i==0) K/=i;
    }
    P = K;
    if(P!=1) act();
    cout << out;
}