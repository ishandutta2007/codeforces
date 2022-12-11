#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> p,z;
vector <pair<int,int>> m;
bool sortcmp(pair<int,int> x, pair<int,int> y)
{
    return x.first > y.first;
}
int main()
{
    cin >> n;
    int zero=0,minu=0,str[200010];
    for(int i=1; i<=n; i++)
    {
        int num;
        cin >> num;
        if(num==0)
        {
            zero++;
            str[i] = 0;
            z.push_back(i);
        }
        else if(num<0)
        {
            minu++;
            str[i] = -1;
            m.push_back(pair<int,int>(num,i));
        }
        else if(num>0)
        {
            str[i] = 1;
            p.push_back(i);
        }
    }
    sort(m.begin(),m.end(),sortcmp);
    if(zero)
    {
        int sz = z.size();
        for(int i=0; i<sz-1; i++) cout << 1 << ' ' << z[i] << ' ' << z[i+1] << '\n';
        if(minu%2)
        {
            cout << 1 << ' ' << z[sz-1] << ' ' << m[0].second << '\n';
            if(p.size() || m.size()>1) cout << 2 << ' ' << m[0].second << '\n';
            if(m.size()>1) for(int i=1; i<m.size()-1;i++) cout << 1 << ' ' << m[i].second << ' ' << m[i+1].second << '\n';
            if(p.size() && m.size()>1) cout << 1 << ' '<< m[m.size()-1].second << ' ' << p[0] << '\n';
            if(p.size()>1) for(int i=0; i<p.size()-1;i++) cout << 1 << ' ' << p[i] << ' ' << p[i+1] << '\n';
        }
        else
        {
            if(z.size()!=n)
            {
                cout << 2 << ' '  << z[sz-1] << '\n';
                if(m.size()) for(int i=0; i<m.size()-1;i++) cout << 1 << ' ' << m[i].second << ' ' << m[i+1].second << '\n';
                if(m.size()>1 && p.size()) cout << 1 << ' '<< m[m.size()-1].second << ' ' << p[0] << '\n';
                if(p.size()>1) for(int i=0; i<p.size()-1;i++) cout << 1 << ' ' << p[i] << ' ' << p[i+1] << '\n';
            }
        }
    }
    else
    {
        if(minu%2)
        {
            if(p.size() || m.size()>1) cout << 2 << ' ' << m[0].second << '\n';
            if(m.size()>1) for(int i=1; i<m.size()-1;i++) cout << 1 << ' ' << m[i].second << ' ' << m[i+1].second << '\n';
            if(m.size()>1 && p.size()) cout << 1 << ' '<< m[m.size()-1].second << ' ' << p[0] << '\n';
            if(p.size()>1) for(int i=0; i<p.size()-1;i++) cout << 1 << ' ' << p[i] << ' ' << p[i+1] << '\n';
        }
        else
        {
            if(m.size()>1) for(int i=0; i<m.size()-1;i++) cout << 1 << ' ' << m[i].second << ' ' << m[i+1].second << '\n';
            if(m.size()>1 && p.size()) cout << 1 << ' '<< m[m.size()-1].second << ' ' << p[0] << '\n';
            if(p.size()>1) for(int i=0; i<p.size()-1;i++) cout << 1 << ' ' << p[i] << ' ' << p[i+1] << '\n';
        }
    }
}