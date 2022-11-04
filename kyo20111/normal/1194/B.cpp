#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,r[50505],c[50505];
string s[50505];
int main(){
    cin >> t;
    while(t--){
        vector<int> v;
        cin >> n >> m;
        for(int i=0;i<n;i++) r[i]=0;
        for(int i=0;i<m;i++) c[i]=0;
        for(int i=0;i<n;i++) cin>>s[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) if(s[i][j] == '*') r[i]++;
            r[i] = n-r[i];
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) if(s[j][i] == '*') c[i]++;
            c[i] = m-c[i];
        }
        int ans = 1e9;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) ans=min(ans,r[i]+c[j]-(s[i][j]=='.'));
        cout << ans << "\n";
    }
}