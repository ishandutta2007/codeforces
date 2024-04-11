#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> ti3;
const ll INF= 1LL<<60;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--){
        string s,t;
        cin >> s >> t;
        int n = s.size(),m = t.size();
        int j = m-1;
        int fq[26]={};
        for(int i=n-1;i>=0;i--){
            if(j>=0&&s[i]==t[j]){
                if(fq[s[i]-'A']){
                    break;
                }
                j--;
            }
            else fq[s[i]-'A']++;
        }
        if(j==-1){
            cout <<"YES\n";
        }
        else cout << "NO\n";
    }
}