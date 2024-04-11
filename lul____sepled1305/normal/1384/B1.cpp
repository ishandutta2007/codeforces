#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,k,l,i;
        bool pass = true;
        cin>>n>>k>>l;
        int depth[n];
        bool safe[n];
        for(i=0;i<n;i++)
            cin>>depth[i];
        for(i=0;i<n;i++)
        {
            if(depth[i] + k <=l)
                safe[i] = true;
            else
                safe[i] = false;
        }
        int cur = 0;
        int place = -1;
        while(place<n-1)
        {
            if(place == -1 || safe[place])
            {
                int first_good = l - depth[place+1];
                if(first_good < 0)
                {
                    pass = false;
                    break;
                }
                else
                {
                    cur = 2*k-first_good;
                    if(cur == 2*k)
                        cur = 0;
                    place++;
                }
            }
            else
            {
                if(cur == 2*k-1 && depth[place+1] <= l)
                {
                    place++;
                    cur = 0;
                }
                else if(depth[place+1] >l)
                {
                    pass = false;
                    break;
                }
                else
                {
                    int first_good = l - depth[place+1];
                    if(cur < k)
                    {
                        if(first_good >= cur+1)
                        {
                            cur++;
                            place++;
                        }
                        else
                        {
                            pass = false;
                            break;
                        }
                    }
                    else
                    {
                        cur = max(2*k-first_good,cur+1);
                        if(cur > 2*k)
                        {
                            pass = false;
                            break;
                        }
                        else if(cur == 2*k)
                        {
                            cur = 0;
                        }
                        place++;
                    }
                }
            }
        }
        if(pass)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}