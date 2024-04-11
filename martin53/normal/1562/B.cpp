#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,k;

char inp[nmax];

vector<string> out;

void solve()
{
    //cout<<"---"<<endl;

    cin>>n;

    for(int i=1;i<=n;i++)cin>>inp[i];

    for(auto w:out)
    {
        int SZ=0;

        for(int i=1;i<=n&&SZ<w.size();i++)
            if(inp[i]==w[SZ])SZ++;

        if(SZ==w.size())
        {
            cout<<w.size()<<"\n"<<w<<"\n";
            return;
        }
    }

}

bool ok(int i)
{
    if(i==1)return 1;

    for(int p=2;p*p<=i;p++)
        if(i%p==0)return 1;

    return 0;
}

int main()
{
    for(int i=1;i<100;i++)
        if(ok(i))
        {
            string cur="";

            int j=i;

            while(j)
            {
                cur.push_back(char(j%10+'0'));

                j=j/10;
            }

            reverse(cur.begin(),cur.end());

            //cout<<"cur= "<<cur<<endl;

            out.push_back(cur);
        }

    int t;
    cin>>t;

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}