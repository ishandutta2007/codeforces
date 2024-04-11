#include <bits/stdc++.h>
using namespace std;
#define va first
#define vb second
typedef long long ll;
typedef pair<int,int> pii;
using namespace std;
const int MN = 510;
const int INF = 1e9;

int A[MN],B[MN],D[MN][MN],N,M,K,cnt,tmp,ans,val;
string S;

int func(int a, int b)
{
    if(a>b) return 0;
    if(a==b) return 1;
    if(D[a][b]!=-1) return D[a][b];
    int res = func(a+1,b)+1;
    for(int i=a+1; i<=b; i++){
        if(S[i]==S[a]){
            res = min(res,func(a+1,i-1)+func(i,b));
        }
    }
    return D[a][b] = res;
}

int main()
{
    //ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> S;
    for(int i=0; i<MN; i++)
        for(int j=0; j<MN; j++)
            D[i][j] = -1;
    cout << func(0,N-1);
}