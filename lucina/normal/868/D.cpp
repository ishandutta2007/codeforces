#include<bits/stdc++.h>
using namespace std;
string s[205];

int solve(string t){
    for(int i=1;i<= 10;i++){
        for(int j=0;j<(1<<i);j++){
            string ret;
            for(int k=0;k<i;k++)
                ret += (j & (1<<k))? '1':'0';
            if(t.find(ret) == -1) return i - 1;
        }
    }
}
int c[205];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> s[i];
    int m; cin >>m;
    int u,v;
    for(int i= n + 1 ;i<=n + m;i++){
        cin >> u >> v;
        s[i] = s[u] + s[v];
        if((int)s[i].size() >1000)
            s[i] = s[i].substr(0,500) + s[i].substr((int)s[i].length() - 500,500);
        c[i] = max({c[u],c[v],solve(s[i])});
        cout << c[i] <<'\n';
    }
}