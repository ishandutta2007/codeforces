#include<bits/stdc++.h>
using namespace std;
int n;
int ask_equal(string now)
{
    cout<<"? "<<now<<endl;
    cout.flush();
    int ret;
    cin>>ret;
    return n-ret;
}
int where_zero=-1,where_one=-1;

void test()
{
    if(where_zero!=-1&&where_one!=-1)
    {
        cout<<"! "<<where_zero+1<<" "<<where_one+1<<endl;
        exit(0);
    }
}

void solve(int l,int r,int zeros)
{
    //cout<<l<<" "<<r<<" "<<eq<<endl;
    test();

    if(zeros==0)
    {
        where_one=l;
        test();
        return;
    }
    if(r-l+1==zeros)
    {
        where_zero=l;
        test();
        return;
    }

    int av=(l+r)/2;

}
int main()
{
cin>>n;

string zer="";
for(int i=0;i<n;i++)zer.push_back('0');
int zeros=ask_equal(zer);

zer[0]='1';

if(ask_equal(zer)-zeros==1)where_one=0;
else where_zero=0;

//cout<<where_zero<<" "<<where_one<<endl;
if(where_one!=-1)
{
    int ok=0,not_ok=n;
    while(not_ok-ok>1)
    {
        int av=(ok+not_ok)/2;

        zer="";
        for(int j=0;j<=av;j++)zer.push_back('1');
        for(int j=av+1;j<n;j++)zer.push_back('0');

        if(ask_equal(zer)-zeros==av+1)ok=av;
        else not_ok=av;
    }
    where_zero=not_ok;
    test();
}
else//where_zero!=-1
{
    zer="";
    for(int i=0;i<n;i++)zer.push_back('1');
    int ones=ask_equal(zer);

    int ok=0,not_ok=n;
    while(not_ok-ok>1)
    {
        int av=(ok+not_ok)/2;

        zer="";
        for(int j=0;j<=av;j++)zer.push_back('0');
        for(int j=av+1;j<n;j++)zer.push_back('1');

        if(ask_equal(zer)-ones==av+1)ok=av;
        else not_ok=av;
    }
    where_one=not_ok;
    test();

}
return 0;
}