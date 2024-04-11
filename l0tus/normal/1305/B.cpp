#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 2e3+5;
int ans;
bool ch[MN];
vector<int> C[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    string S;
    cin >> S;
    int st,en;
    while(1){
        st = 0, en = S.size()-1;
        while(st<en){
            if(ch[st]){
                ++st;
                continue;
            }
            if(ch[en]){
                --en;
                continue;
            }
            if(S[st]=='('&&S[en]==')'){
                C[ans].push_back(st);
                C[ans].push_back(en);
                ch[st] = ch[en] = 1;
                continue;
            }
            if(S[st]==')') ++st;
            if(S[en]=='(') --en;
        }
        sort(C[ans].begin(),C[ans].end());
        if(C[ans].size()) ++ans;
        else break;
    }
    cout << ans << '\n';
    for(int i=0; i<ans; i++){
        cout << C[i].size() << '\n';
        for(int x:C[i])
            cout << x+1 << ' ';
        cout << '\n';
    }
}