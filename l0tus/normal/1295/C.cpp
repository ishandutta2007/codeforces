#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        string A,B;
        vector<int> V[26];
        cin >> A >> B;
        for(int i=0; i<A.size(); i++){
            V[A[i]-'a'].push_back(i);
        }
        for(int i=0; i<26; i++) V[i].push_back(A.size());
        int cur = 0, ans = 0;
        bool ch = 0;
        for(int i=0; i<B.size(); i++){
            if(cur==0) ans++;
            int val = B[i]-'a';
            auto it = lower_bound(V[val].begin(),V[val].end(),cur);
            //cout << *it << '\n';
            if(*it == A.size()){
                if(cur==0){
                    ch = 1;
                    break;
                }
                else{
                    cur=0;
                    i--;
                }
            }
            //V[val][lower_bound(V[val].begin(),V[val].end(),cur)-V[val].begin()]
            else cur = (*it)+1;
        }
        if(ch) cout << "-1\n";
        else cout << ans << '\n';
    }
}