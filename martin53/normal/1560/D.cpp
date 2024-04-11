#include<bits/stdc++.h>
using namespace std;

vector< string > given;

string get_string(long long help)
{
    string now="";

    while(help)
    {
        now.push_back(help%10+'0');
        help=help/10;
    }

    reverse(now.begin(),now.end());

    return now;
}

int common(string a,string b)
{
    int pointer=0;

    for(auto w:a)
    {
        if(pointer<b.size()&&b[pointer]==w)pointer++;
    }

    return pointer;
}
int solve()
{
    int n;

    cin>>n;

    string n_=get_string(n);

    int outp=1e9;

    for(auto p:given)
    {
        int cur=n_.size()+p.size()-2*common(n_,p);

        outp=min(outp,cur);
    }

    return outp;
}

int main()
{
    int t;
    cin>>t;

    long long val=1;

    while(val<1e18)
    {
        given.push_back(get_string(val));

        val=val*2;
    }

    while(t)
    {
        t--;

        cout<<solve()<<"\n";
    }

    return 0;
}