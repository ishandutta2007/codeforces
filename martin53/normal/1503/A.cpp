#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;

string s;

string a="";
string b="";

bool check(string cur)
{
    int sum=0;

    for(auto w:cur)
        if(w=='(')sum++;
        else
        {
            if(sum==0)return 0;
            sum--;
        }
    return sum==0;
}
void solve()
{
    cin>>n>>s;

    a="";
    b="";

    int cnt=0;

    int add=0;

    for(auto w:s)
        if(w=='1')
        {
            a.push_back('(');
            b.push_back('(');

            add++;
        }
        else
        {
            if(cnt%2==0)
            {
                a.push_back('(');
                b.push_back(')');
            }
            else
            {
                a.push_back(')');
                b.push_back('(');
            }

            cnt++;
        }


    if(add%2)
    {
        cout<<"NO\n";
        return;
    }

    add=add/2;

    for(int i=n-1;i>=0&&add;i--)
        if(s[i]=='1')
        {
            a[i]=')';
            b[i]=')';

            add--;
        }

    if(check(a)&&check(b))
    {
        cout<<"YES\n";
        cout<<a<<"\n";
        cout<<b<<"\n";
        return;
    }

    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}