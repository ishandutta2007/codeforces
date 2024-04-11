/**Nephren is the best girl**/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int MOD = 1e9+7;
const int chtholly = 0;
int T;

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
    {
        int n,i,j,k,mini = 1e9;
        string s;
        cin>>s;
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                if(j==i)
                    continue;

                bool first  = true;
                bool val = true;
                int gg  =s.size();
                int left = 0, right = 0,counti = 0;
                for(k=0;k<gg;k++)
                {
                    int cur = s.at(k)-'0';
                    if(cur == i)
                        counti++;
                    if(cur == i && first)
                    {
                        first = false;
                        val = true;
                        left++;
                    }
                    else if(cur == i && !val)
                    {
                        val = true;
                        left++;
                    }
                    else if(cur == j && first)
                    {
                        val = false;
                        right++;
                    }
                    else if(cur == j && val)
                    {
                        val = false;
                        right++;
                    }
                }
                mini = min(mini,gg-2*min(left,right));
                mini = min(mini,gg-counti);
            }

        }
        cout<<mini<<"\n";
    }
    return chtholly;
}

/**
    I lied. Ithea is better than Nephren.
    JK
**/