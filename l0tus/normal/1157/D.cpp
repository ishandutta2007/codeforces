#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
long long N,K,A[MN],B,C,S,ans,sum,val,cnt;
bool ch;
queue<long long> Q;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> K;
    cnt = 1;
    A[0] = 1;
    for(int i=1; i<33; i++) A[i] = 2*A[i-1];
    while(K){
        if(K<33) while(cnt*(A[K]-1)<N){
            cnt++;
        }
        Q.push(cnt);
        K--;
        N-=cnt;
        cnt++;
    }
    if(N==0){
        cout << "YES\n";
        while(!Q.empty()){
            cout << Q.front() << ' ';
            Q.pop();
        }
    }
    else cout << "NO";
    /*if(N>=K*(K+1)/2 && N<(1<<K) || N>=K*(K+3)/2){
        cout << "YES\n";
        while(K){
            while(cnt*((1<<K)-1)<N) cnt++;
            cout << cnt << ' ';
            K--;
            N-=cnt;
            cnt++;
        }
    }
    else{
        cout << "NO";
    }*/
}