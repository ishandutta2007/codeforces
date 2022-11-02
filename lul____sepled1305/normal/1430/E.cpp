#include<bits/stdc++.h>
using namespace std;
int n,i,j,k;
long long ans;
string s;
vector<int> val;

int main()
{
    cin>>n>>s;
    for(i=0;i<n;i++)
    {
        int cur = s[i]-'a';
        val.push_back(cur);
    }
    for(i=0;i<26;i++)
    {
        for(j=0;j<i;j++)
        {
            vector<int> sus;
            vector<int> rev;
            for(k=0;k<n;k++)
            {
                if(val[k] == i)
                    sus.push_back(1), rev.push_back(1);
                if(val[k] == j)
                    sus.push_back(2), rev.push_back(2);
            }
            reverse(rev.begin(),rev.end());
            vector<int> pos, pos_rev;
            for(k=0;k<sus.size();k++)
            {
                if(sus[k]==1)
                    pos.push_back(k);
                if(rev[k]==1)
                    pos_rev.push_back(k);
            }
            for(k=0;k<pos.size();k++)
            {
                ans+=abs(pos[k]-pos_rev[k]);
            }
        }
    }
    cout<<ans;
    return 0;
}