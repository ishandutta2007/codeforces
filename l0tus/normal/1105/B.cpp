#include <bits/stdc++.h>
using namespace std;
#define va first
#define vb second
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 1e5;
const int INF = 1e9;

long long N,M,L,sum,ans,cnt,A[MN],B[MN];
string S;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> L >> S;

    for(int j=0; j<26; j++)
    {
        for(int i=0; i<S.size(); i++)
        {
            if(S[i]-'a'==j)
                cnt++;
            else
            {
                sum += cnt/L;
                cnt = 0;
            }
        }
        sum += cnt/L;
        cnt = 0;
        ans = max(sum,ans);
        sum = 0;
    }
    cout << ans;
}