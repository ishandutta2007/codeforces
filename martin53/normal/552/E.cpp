#include<bits/stdc++.h>
using namespace std;
string make_string(long long value)
{
    string s="";
    while(value)
    {
    s=char(value%10+'0')+s;
    value=value/10;
    }
    return s;
}
long long evaluate(string s)
{
    //cout<<"evaluate: ";cout<<s;
    int beg=0,SZ=s.size();
    long long sum=0;
    while(beg<SZ)
    {
        int pos=beg;
        while(pos<SZ&&s[pos]!='+')pos++;
        pos--;
        long long prod=1,number=0;
        for(int j=beg;j<=pos;j++)
            if(s[j]=='*')
            {
            prod=prod*number;
            number=0;
            }
            else
            {
            number=number*10+(s[j]-'0');
            }
        prod=prod*number;
        sum=sum+prod;

        beg=pos+2;
    }
    //cout<<" -> "<<sum<<endl;
    return sum;
}
int main()
{
string inp;
cin>>inp;
inp="1*"+inp+"*1";
long long ans=0;
int n=inp.size();
for(int l=0;l<n;l++)
    for(int r=l+1;r<n;r++)
    if(inp[l]=='*'&&inp[r]=='*')
    {
    string now="";
    for(int k=0;k<=l;k++)now.push_back(inp[k]);

    string work="";
    for(int k=l+1;k<r;k++)work.push_back(inp[k]);
    long long value=evaluate(work);
    now=now+make_string(value);

    for(int k=r;k<n;k++)now.push_back(inp[k]);

    ans=max(ans,evaluate(now));
    }
cout<<ans<<endl;
return 0;
}