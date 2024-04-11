#include<bits/stdc++.h>
using namespace std;

struct info
{
    long long score;

    string from,to;
};

map<string,info> seen;

int cnt(string str)
{
    int ret=0;

    string match="haha";

    for(int i=0;i+match.size()-1<str.size();i++)
    {
        bool ok=1;

        for(int j=0;j<match.size()&&ok;j++)
            ok=(str[i+j]==match[j]);

        ret+=ok;
    }

    return ret;
}

info init(string str)
{
    info ret;
    ret.score=0;
    ret.from="";
    ret.to="";

    for(int i=0;i<str.size()&&i<=2;i++)
    {
        ret.from.push_back(str[i]);
        ret.to.push_back(str[str.size()-1-i]);
    }

    reverse(ret.to.begin(),ret.to.end());

    ret.score=cnt(str);

    return ret;
}

info my_merge(info a,info b)
{
    info ret;

    ret.score=a.score+b.score+cnt(a.to+b.from);

    if(a.from.size()<3)
    {
        ret.from=a.from+b.from;

        while(ret.from.size()>3)ret.from.pop_back();
    }
    else ret.from=a.from;

    if(b.to.size()<3)
    {
        ret.to=a.to+b.to;

        while(ret.to.size()>3)ret.to.erase(ret.to.begin(),ret.to.begin()+1);
    }
    else ret.to=b.to;

    return ret;
}
long long solve()
{
    seen={};

    int n;
    cin>>n;

    long long ret=0;

    for(int i=1;i<=n;i++)
    {
        string inp;

        string type;

        cin>>inp>>type;

        if(type==":=")
        {
            string cur;

            cin>>cur;

            seen[inp]=init(cur);
        }
        else
        {
            string a,idle,b;

            cin>>a>>idle>>b;

            seen[inp]=my_merge(seen[a],seen[b]);
        }

        ret=seen[inp].score;

        //cout<<"ret= "<<seen[inp].score<<" "<<seen[inp].from<<" "<<seen[inp].to<<endl;
    }

    return ret;
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

        cout<<solve()<<"\n";
    }

    return 0;
}