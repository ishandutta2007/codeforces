/**Ithea is a nice girl.**/
#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
    {
        int n,i,j;
        cin>>n;
        int a,local_min = -1,cur = 0;
        vector<int> rang;
        for(i=0;i<2*n;i++)
        {
            cin>>a;
            if(a>local_min)
            {
                local_min = a;
                rang.push_back(cur);
                cur = 1;
            }
            else
                cur++;
        }
        rang.push_back(cur);
        bool pos[n+1];
        for(i=0;i<=n;i++)
            pos[i] = false;
        pos[0] = true;
        for(i=0;i<rang.size();i++)
        {
            for(j=n;j>=0;j--)
            {
                if(pos[j] && j+rang[i]<=n)
                    pos[j+rang[i]] = true;
            }
        }
        if(pos[n])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

/**
3
1 1
69 420
148 320
**/