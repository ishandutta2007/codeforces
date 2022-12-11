#include <bits/stdc++.h>
using namespace std;
#define va first
#define vb second
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 1e5;
const int INF = 1e9;

long long N,M,L,ans,cnt,sum,A[MN],B[MN];
string S;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> S;
    stack<char> Q;
    for(int i=0; i<S.size(); i++){
        if(!Q.empty() && S[i]==Q.top()){
            cnt++;
            Q.pop();
        }
        else Q.push(S[i]);
    }
    if(cnt%2) cout << "Yes";
    else cout << "No";
}