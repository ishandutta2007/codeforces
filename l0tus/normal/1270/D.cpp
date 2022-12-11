#include <bits/stdc++.h>
#define va firsst
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MN = 1000;
int N,K,x,pos,A,p,y,C[MN],M;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> K;
    if(K==1){
        cout << "! " << 1;
        return 0;
    }
    cout << '?' << ' ';
    for(int i=1; i<=K; i++) cout << i << ' ';
    cout.flush();
    cin >> pos >> x;
    A = 1;
    if(pos==1) A = 2;
    for(int j=K+1; j<=N; j++){
        cout << '?' << ' ';
        for(int i=1; i<=K; i++) if(i!=A) cout << i << ' ';
        cout << j << ' ';
        cout.flush();
        cin >> p >> y;
        if(y>x) C[A] = -1, C[j] = 1;
        if(y<x) C[A] = 1, C[j] = -1;
    }
    for(int j=1; j<=K; j++){
        if(j==pos||j==A) continue;
        cout << '?' << ' ';
        for(int i=1; i<=K+1; i++) if(i!=j) cout << i << ' ';
        cout.flush();
        cin >> p >> y;
        if(y>x) C[j] = -1, C[K+1] = 1;
        if(y<x) C[j] = 1, C[K+1] = -1;
    }
    if(C[K+1]==0) C[K+1] = C[A];
    for(int j=1; j<=K; j++) if(C[j]==0&&j!=pos) C[j]=C[K+1];
    if(C[A]==0) C[A] = C[K+1];
    for(int j=K+1; j<=N; j++) if(C[j]==0) C[j]=C[A];
    if(C[A]!=0){
        for(int i=1; i<=K; i++){
            if(i==pos) continue;
            if(C[i]==-1) M++;
        }
        cout << "! " << M+1;
    }
    else{
        cout << '?' << ' ';
        for(int j=1; j<=K+1; j++) if(j!=pos) cout << j << ' ';
        cout.flush();
        cin >> p >> y;
        if(y>x) cout << "! " << 1;
        if(y<x) cout << "! " << K;
    }
}