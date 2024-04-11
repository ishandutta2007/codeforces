#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n;
char inp[nmax];
void in()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    string s;
    cin>>s;

    n=s.size();
    for(int i=1;i<=n;i++)
        inp[i]=s[i-1];
}

long long pref[nmax];
long long ask(int w)// x/y=w
{
    pref[0]=0;

    long long sum=0,ret=0;

    for(int i=1;i<=n;i++)
    {
        if(inp[i]=='1')sum=sum+w-1;
        else sum--;

        pref[i]=sum;
    }

    sort(pref,pref+n+1);

    int current=1;

    for(int i=1;i<=n;i++)
    {
        if(pref[i]==pref[i-1])current++;
        else current=1;

        ret=ret+current-1;
    }

    return ret;
}

int ones[nmax],id=0;

int cnt(int i,int j,int ri,int mx_size)
{
    int size_from=ri-ones[i]+1;
    int size_to=ri-ones[i-1];

    size_to=min(size_to,mx_size);

    if(size_from>size_to)return 0;

    int ones_now=j-i+1;

    return size_to/ones_now-(size_from-1)/ones_now;
}
int main()
{
    in();
    for(int i=1;i<=n;i++)
        if(inp[i]=='1')
        {
            id++;
            ones[id]=i;
        }

    ones[id+1]=n+1;

    long long output=0;

    int MX=300;

    for(int w=1;w<=MX;w++)
        output=output+ask(w);

    for(int a=1;a*(MX+1)<=n;a++)
    {
        //O(n) per a
        int b_least=a*(MX+1);
        for(int j=a;j<=id;j++)
        {
            int i=j-a+1;
            //ones are [i,j]
            for(int ri=ones[j];ri<ones[j+1];ri++)
            {
                output=output+cnt(i,j,ri,1e9)-cnt(i,j,ri,b_least-1);
            }
        }
    }

    cout<<output<<endl;
    return 0;
}