#include <bits/stdc++.h>
#define va firsst
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MN = 2e5+5;
int N,A[2],ans=MN,l,r,s,e,S[MN],x,y,val,cnt,tmp;
vector<int> X[2];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    if(N==1){
        cout << 0;
        return 0;
    }
    for(int i=1; i<=N; i++){
        A[i%2]++;
    }
    for(int i=0; i<N; i++){
        cin >> S[i];
        if(S[i]){
            A[S[i]%2]--;
        }
    }
    x = 0, y = N-1;
    if(S[x]==0) while(S[x]==0&&x<N) x++;
    if(x==N){
        cout << 1;
        return 0;
    }
    if(S[y]==0) while(S[y]==0) y--;
    for(int i=x+1; i<=y; i++){
        if(S[i]==0){
            if(S[i-1]!=0){
                l = S[i-1]%2;
                s = i;
            }
            continue;
        }
        if(S[i-1]!=0){
            if(S[i-1]%2!=S[i]%2) val++;
        }
        else{
            r = S[i]%2;
            e = i;
            if(l==r){
                X[l%2].push_back(e-s);
            }
            else val++;
        }
    }
    sort(X[0].begin(),X[0].end());
    sort(X[1].begin(),X[1].end());
    if(A[S[x]%2]>=x){
        A[S[x]%2] -= x;
        if(A[S[y]%2]>=N-1-y){
            A[S[y]%2] -= N-1-y;
            tmp = val;
            cnt = A[0];
            for(int i=0; i<X[0].size(); i++){
                if(cnt>=X[0][i]) cnt-=X[0][i];
                else tmp += 2;
            }
            cnt = A[1];
            for(int i=0; i<X[1].size(); i++){
                if(cnt>=X[1][i]) cnt-=X[1][i];
                else tmp += 2;
            }
            ans = min(ans,tmp);
            A[S[y]%2] += N-1-y;
        }
        tmp = val+1;
        cnt = A[0];
        for(int i=0; i<X[0].size(); i++){
            if(cnt>=X[0][i]) cnt-=X[0][i];
            else tmp += 2;
        }
        cnt = A[1];
        for(int i=0; i<X[1].size(); i++){
            if(cnt>=X[1][i]) cnt-=X[1][i];
            else tmp += 2;
        }
        ans = min(ans,tmp);
        A[S[x]%2] += x;
    }
    if(A[S[y]%2]>=N-1-y){
        A[S[y]%2] -= N-1-y;
        tmp = val+1;
        cnt = A[0];
        for(int i=0; i<X[0].size(); i++){
            if(cnt>=X[0][i]) cnt-=X[0][i];
            else tmp += 2;
        }
        cnt = A[1];
        for(int i=0; i<X[1].size(); i++){
            if(cnt>=X[1][i]) cnt-=X[1][i];
            else tmp += 2;
        }
        ans = min(ans,tmp);
        A[S[y]%2] += N-1-y;
    }
    tmp = val+2;
    cnt = A[0];
    for(int i=0; i<X[0].size(); i++){
        if(cnt>=X[0][i]) cnt-=X[0][i];
        else tmp += 2;
    }
    cnt = A[1];
    for(int i=0; i<X[1].size(); i++){
        if(cnt>=X[1][i]) cnt-=X[1][i];
        else tmp += 2;
    }
    ans = min(ans,tmp);
    cout << ans;
}