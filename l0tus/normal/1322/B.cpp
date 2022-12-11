#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int A[25],I[25],ans;
ll C[25];
vector<int> V[25];

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N;
    cin >> N;
    for(int k=0; k<=25; k++) I[k] = 1<<k;
    for(int j=1; j<=N; j++){
        int x;
        cin >> x;
        int cnt = 0;
        for(int i=0; i<25; i++) A[i] = 0;
        while(x){
            A[cnt] = x%2;
            ++cnt;
            x/=2;
        }
        for(int i=0; i<25; i++){
            if(A[i]) x += I[i];
            V[i].push_back(x);
        }
    }
    for(int i=0; i<25; i++){
        sort(V[i].begin(),V[i].end());
        for(int j=0; j<N; j++){
            int x = V[i][j];
            C[i] += lower_bound(V[i].begin(),V[i].end(),I[i+1]-x)-lower_bound(V[i].begin(),V[i].end(),I[i]-x);
            C[i] += N-(lower_bound(V[i].begin(),V[i].end(),I[i+1]+I[i]-x)-V[i].begin());
            if((2*x)&I[i]) C[i]--;
        }
    }
    for(int i=0; i<25; i++){
        C[i]/=2;
        if(C[i]%2) ans += I[i];
    }
    cout << ans;
}