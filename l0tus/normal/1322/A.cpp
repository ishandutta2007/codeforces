#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 2e5+5;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N;
    cin >> N;
    string S;
    cin >> S;
    int cnt = 0;
    int st = -1, en = -1, ans = 0;
    for(int i=0; i<N; i++){
        if(S[i]=='(') ++cnt;
        else --cnt;
        if(st==-1&&cnt<0) st = i;
        if(st!=-1&&cnt==0){
            ans += i-st+1;
            st = -1;
        }
    }
    if(cnt!=0){
        cout << -1;
        return 0;
    }
    cout << ans;
}