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
        string a,b;
        cin>>n>>a>>b;
        vector<int> fi,se;
        vector<int> flip;
        int cur_flip=0;
        int val = 0;
        for(i=0;i<n;i++)
        {
            fi.push_back(a.at(i)-'0');
            se.push_back(b.at(i)-'0');
        }
        for(i=n-1;i>=0;i--)
        {
            int cur_i,cur_0;
            if(cur_flip)
                cur_i = val-i;
            else
                cur_i = val+i;
            cur_0 = val;
            if(fi[cur_i]^cur_flip!=se[i])
            {
                if(fi[cur_0]^cur_flip!=se[i])
                {
                    flip.push_back(i);
                    cur_flip = cur_flip^1;
                    if(cur_flip)
                        val+=i;
                    else
                        val-=i;
                }
                else
                {
                    flip.push_back(0);
                    fi[cur_0] = fi[cur_0]^1;
                    i++;
                }
            }
        }
        cout<<flip.size()<<" ";
        for(auto it: flip)
            cout<<it+1<<" ";
        cout<<"\n";
    }
    return 0;
}

/**
3
1 1
69 420
148 320
**/