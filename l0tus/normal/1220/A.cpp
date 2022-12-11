#include <bits/stdc++.h>
#define first va
#define second vb
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
int N,A[MN],B[MN],cnt,ans,a,b,c,m,M;
bool ch;
string S;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> S;
    for(int i=0; i<N; i++){
        if(S[i]=='z') a++;
        if(S[i]=='n') b++;
    }
    while(b){
        cout << 1 << ' ';
        b--;
    }
    while(a){
        cout << 0 << ' ';
        a--;
    }
}