#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> pref(string s)
{
    int n = s.length();
    vector<int> p(n, 0);
    for(int i = 1, k = 0; i < n; ++i)
    {
        while(k && s[i] != s[k]) 
            k = p[k - 1];
        if(s[i] == s[k])
            ++k;
        p[i] = k;
    }
    return p;
}

string min_conc(string a, string b)
{
    vector<int> p = pref(a + '#' + b);
    int last = p.back();
    
    string res = b;
    for(int i = 0; i < p.size(); ++i)
        if(p[i] == a.length())
            return b;
            
    for(int i = last; i < a.length(); ++i)
        res += a[i];
    
    return res;
}

int len(string a, string b, string c)
{
    string s;
    s = min_conc(min_conc(a, b), c);
    return s.length();
}

int min(int a, int b, int c, int d, int e, int f)
{
    int res = a;
    res = min(res, b);
    res = min(res, c);
    res = min(res, d);
    res = min(res, e);
    res = min(res, f);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    string a, b, c;
    cin >> a >> b >> c;
    
    cout << min(len(a, b, c), len(a, c, b), len(b, a, c), len(b, c, a), len(c, a, b), len(c, b, a));
    
    cin >> a;
    
    return 0;
}