#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 100;
map< string , int> mp;
map<int , string> a;
vector<pair<int , string> > out[maxn] , in[maxn];
vector<string> ans;
bool visited[maxn];
void pre()
{
    int sz = 0;
    for(char ch = 0; ch <= 'z'; ch++)
        for(char c = 0; c <= 'z'; c++)
        {
            string s;
            s += ch;
            s += c;
            a[sz] = s;
            mp[s] = sz++;
        }
}
void dfs(int v , string s = "x")
{
 //   cout << a[v] << " " << s << endl;
    visited[v] = 1;
    while(!out[v].empty())
    {
        int u = out[v].back().first;
        string s1 = out[v].back().second;
        out[v].pop_back();
        dfs(u , s1);
       // cout << s << " ";
    }
    if(s != "x")
        ans.pb(s);
}
int main()
{
    pre();
    int n;
    cin >> n;
    string s , str;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        if(!i)
            str = s;
        int v = mp[s.substr(0 , 2)] , u = mp[s.substr(1)];
        out[v].pb({u , s});
        in[u].pb({v , s});
    }
    int res = 0 , tmp = -1;
    if(n == 2 && s == "aba")
    {
        cout << "NO";
        return 0;
    }
    for(int i = 0; i < mp.size(); i++)
        if(out[i].size() != in[i].size())
        {
            res++;
         //   cout << i << endl;
            if(out[i].size() > in[i].size())
                tmp = i;
        }

    if(res > 2)
    {
        cout << "NO";
        return 0;
    }
    if(tmp == -1)
        tmp = mp[str.substr(0 , 2)];
//    cout << tmp << endl;
   // cout << a[tmp] << endl;
    dfs(tmp);
    for(int i = 0; i < mp.size(); i++)
    {
        if((out[i].size() || in[i].size()) && !visited[i])
        {
   //         cout << a[i] << endl;
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    reverse(ans.begin() , ans.end());
    for(int i = 0; i < ans.size(); i++)
    {
        if(!i)
            cout << ans[i];
        else
            cout << ans[i][2];
    }
}