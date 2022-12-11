#include <bits/stdc++.h>
#define va firsst
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MN = 1e6+5;
ll N,M,A[MN],res,tmp,cnt,ans;
bool ch[MN];
bool cmp(int u, int v)
{
    //return A[u]<A[v];
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=2; i<MN; i++){
        if(ch[i]) continue;
        for(int j=2; i*j<MN; j++) ch[i*j] = 1;
        if(N%i==0){
            while(N%i==0) N/=i;
            if(N==1){
                cout << i;
                return 0;
            }
            cout << 1;
            return 0;
        }
    }
    cout << N;
}