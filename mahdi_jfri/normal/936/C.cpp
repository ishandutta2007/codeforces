#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e3 + 20;

int a[maxn];

vector<int> ans;

string s;

void ok(int len)
{
    ans.pb(len);
    int n  = s.size();

    reverse(s.begin() , s.begin() + n - len);
    reverse(s.begin() , s.end());
}

int main()
{
    int n;
    string t;
    cin >> n >> s >> t;

    for(int i = 0; i < n; i++)
        a[s[i] - 'a']++;
    for(int i = 0; i < n; i++)
        a[t[i] - 'a']--;

    for(int i = 0; i < 26; i++)
        if(a[i] != 0)
            return cout << -1 << endl , 0;

    int l , r;
    for(int i = 0; i < n; i++)
        if(s[i] == t[0])
            l = r = i;

    s[l] = s[l] - 'a' + 'A';
    bool jolo = 1;
    for(int i = 1; i < n; i++)
    {
        l = n , r = -1;
        for(int j = 0; j < n; j++)
            if(s[j] < 'a')
                l = min(l , j) , r = max(r , j);
        int c;
        for(int j = 0; j < n; j++)
            if(s[j] == t[i])
                c = j;
        if(jolo)
        {
            ok(n - r - 1);
            ok(r - l + 1);
            for(int j = 0; j < n; j++)
                if(s[j] == t[i])
                    c = j;
            s[c] = s[c] - 'a' + 'A';
            ok(n - c);
            jolo = 0;
        }
        else
        {
            bool x = 0;
            if(l > c)
                x = 1;
            ok(n - c - 1);
            l = n , r = -1;
            for(int j = 0; j < n; j++)
                if(s[j] < 'a')
                    l = min(l , j) , r = max(r , j);
            if(x)
                ok(n - l);
            else
                ok(1);
            l = n , r = -1;
            for(int j = 0; j < n; j++)
                if(s[j] < 'a')
                    l = min(l , j) , r = max(r , j);
            ok(n - l);
            l = n , r = -1;
            for(int j = 0; j < n; j++)
                if(s[j] < 'a')
                    l = min(l , j) , r = max(r , j);
            r++;
            s[r] = s[r] - 'a' + 'A';
            jolo = 1;
        }
    }
    if(!jolo)
        ok(n);

    cout << ans.size() << endl;
    for(auto x : ans)
        cout << x << " ";
    cout << endl;

}