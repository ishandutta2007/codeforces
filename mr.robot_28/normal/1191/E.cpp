#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,k;
char str[MAXN];
vector<int> loc[2];
int main()
{
    scanf("%d%d%s",&n,&k,str);
    for(int i=0;i<n;i++)
        loc[str[i]-'0'].push_back(i);
    if(loc[0].empty() || loc[1].empty())
        return 0*printf("tokitsukaze\n");
    int flag=0;
    for(int l=0,r=k-1;r<n;l++,r++)
    {
        vector<int> tmp[2];
        for(int i=0;i<2;i++)
        {
            if(loc[i].front()<l || loc[i].front()>r)
                tmp[i].push_back(loc[i].front());
            if(loc[i].back()<l || loc[i].back()>r)
                tmp[i].push_back(loc[i].back());
            auto itr=lower_bound(loc[i].begin(),loc[i].end(),l);
            if(itr!=loc[i].begin())
                tmp[i].push_back(*--itr);
            itr=upper_bound(loc[i].begin(),loc[i].end(),r);
            if(itr!=loc[i].end())
                tmp[i].push_back(*itr);
            sort(tmp[i].begin(),tmp[i].end());
        }
        if(tmp[0].empty() || tmp[1].empty())
            return 0*printf("tokitsukaze\n");
        flag|=(tmp[0].back()-tmp[0].front()>=k
            || tmp[1].back()-tmp[1].front()>=k);
    }
    return 0*printf("%s\n",(flag ? "once again" : "quailty"));
}