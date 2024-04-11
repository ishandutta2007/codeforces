#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
vector<char>v[100005];
char c[500005];
int fvdr[500005],fvst[500005];
int main()
{
    long long n,i,j,mn=99999999999,mx=-999999999999,s=0,cnt=0,ok=0,k=0,cnt0=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>c;
        int nc=strlen(c);
        for(j=0;j<nc;++j)
            v[i].push_back(c[j]);
    }
    for(int y=1;y<=n;++y)
    {
        cnt=0;
        int okst=1,okdr=1;
        for(i=0;i<v[y].size();++i)
        {
            if(v[y][i]=='(')
               ++cnt;
            else
               --cnt;
            if(cnt<0)
                okst=0;
        }
        int ccnt=cnt;
        cnt=0;
        for(i=v[y].size()-1;i>=0;--i)
        {
            if(v[y][i]=='(')
                ++cnt;
            else
                --cnt;
            if(cnt>0)
                okdr=0;
        }
        if(ccnt==0 && okst && okdr)
        {
            ++cnt0;
        }
        if(ccnt>0 && okst)
        {
            ++fvst[ccnt];
            while(fvst[ccnt] && fvdr[ccnt])
            {
                --fvst[ccnt];
                --fvdr[ccnt];
                ++s;
            }
        }
        else
        if(ccnt<0 && okdr)
        {
            ccnt=-ccnt;
            ++fvdr[ccnt];
            while(fvst[ccnt] && fvdr[ccnt])
            {
                --fvst[ccnt];
                --fvdr[ccnt];
                ++s;
            }
        }
    }
    s+=cnt0/2;
    cout<<s;
}