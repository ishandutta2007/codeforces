#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int k;
string s,a,b;

int mem[26];

bool ok=0;

int on[26];

void go(int pos,int sure_a,int sure_b)
{
    if(ok)return;

    //cout<<pos<<" "<<sure_a<<" "<<sure_b<<endl;

    if(pos==s.size())
    {
        ok=1;

        //for(int i=0;i<k;i++)cout<<i<<" -> "<<mem[i]<<" "<<on[i]<<endl;

        int help=0;

        for(int i=0;i<k;i++)
            if(mem[i]==-1)
            {
                while(on[help])help++;
                mem[i]=help;
                on[help]=1;
            }

        cout<<"YES"<<"\n";

        for(int i=0;i<k;i++)
            cout<<char(mem[i]+'a');
        cout<<"\n";
        return;
    }

    if(mem[s[pos]-'a']!=-1)
    {
        int cur=mem[s[pos]-'a'];

        int lhs=a[pos]-'a';
        int rhs=b[pos]-'a';

        if(sure_a==0&&lhs>cur)return;
        if(sure_b==0&&rhs<cur)return;

        go(pos+1,sure_a|(lhs<cur),sure_b|(rhs>cur));
        return;
    }

    for(int i=0;i<k&&ok==0;i++)
        if(on[i]==0)
        {
            int cur=i;

            int lhs=a[pos]-'a';
            int rhs=b[pos]-'a';

            if(sure_a==0&&lhs>cur)continue;
            if(sure_b==0&&rhs<cur)continue;

            mem[s[pos]-'a']=i;
            on[i]=1;

            go(pos+1,sure_a|(lhs<cur),sure_b|(rhs>cur));

            mem[s[pos]-'a']=-1;
            on[i]=0;
        }
}
void solve()
{
    cin>>k>>s>>a>>b;

    for(int i=0;i<k;i++)mem[i]=-1,on[i]=0;

    ok=0;

    go(0,0,0);

    if(ok==0)
    {
        cout<<"NO"<<"\n";
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;
        solve();
    }
    return 0;
}