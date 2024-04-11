/**Ogiso Setsuna**/
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
        int n,k,i;
        cin>>n>>k;
        string s;
        bool pos = false;
        bool first = true;
        int cur = 0;
        int W = 0;
        int ne = 0;
        vector<int> neg;
        cin>>s;
        for(i=0;i<n;i++)
        {
            if(s[i] == 'W')
            {
                W++;
                if(first)
                    first = false;
                else if(ne > 0)
                {
                    neg.push_back(ne);
                }
                ne = 0;
                if(pos)
                    cur+=2;
                else
                {
                    pos = true;
                    cur++;
                }
            }
            else
            {
                pos = false;
                ne++;
            }
        }
        sort(neg.begin(),neg.end(),greater<int>());
        if(W + k >= n)
            cout<<2*n-1<<endl;
        else if(W==0)
        {
            if(k==0)
                cout<<0<<endl;
            else
                cout<<2*k-1<<endl;
        }
        else
        {
            while(k> 0 && !neg.empty())
            {
                int val = neg.back();
                neg.pop_back();
                val--;
                cur+=2;
                if(val == 0)
                    cur++;
                else
                    neg.push_back(val);
                k--;
            }
            while(k>0)
            {
                k--;
                cur+=2;
            }
            cout<<cur<<endl;
        }
    }
    return 0;
}