#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int n,m,i,j,k,index;
        bool per = true;
        bool pass = true;
        cin>>n>>m;
        string s[n];
        for(i=0;i<n;i++)
            cin>>s[i];
        string checki;
        for(i=1;i<n;i++)
        {
            int counti=0;
            for(j=0;j<m;j++)
            {
                if(s[i].at(j)!=s[0].at(j))
                    counti++;
            }
            if(counti>2)
            {
                pass = false;
                break;
            }
            if(counti==2)
            {
                index = i;
                per = false;
            }
        }
        if(per)
        {
            for(auto it: s[0])
                checki.push_back(it);
        }
        else
        {
            bool first_ans = true;
            bool second_ans = true;
            bool first = true;
            bool second = true;
            for(i=0;i<m;i++)
            {
                if(s[0].at(i)!=s[index].at(i) && first)
                {
                    checki.push_back(s[index].at(i));
                    first = false;
                }
                else
                {
                    checki.push_back(s[0].at(i));
                }
            }
            for(i=0;i<n;i++)
            {
                int counti = 0;
                for(j=0;j<m;j++)
                {
                    if(checki[j]!=s[i].at(j))
                        counti++;
                }
                if(counti>=2)
                {
                    first_ans = false;
                    break;
                }
            }
            first = true; second = true;
            if(!first_ans)
            {
                while(!checki.empty())
                    checki.pop_back();
                for(i=0;i<m;i++)
                {
                    if(s[0].at(i)!=s[index].at(i) && first)
                    {
                    first = false;
                    checki.push_back(s[0].at(i));
                    }
                    else if (s[0].at(i)!=s[index].at(i) && !first && second)
                    {
                        checki.push_back(s[index].at(i));
                        second = false;
                    }
                    else
                    {
                        checki.push_back(s[0].at(i));
                    }
                }
                for(i=0;i<n;i++)
                {
                    int counti = 0;
                    for(j=0;j<m;j++)
                    {
                        if(checki[j]!=s[i].at(j))
                            counti++;
                    }
                    if(counti>=2)
                    {
                        second_ans = false;
                        break;
                    }
                }
            }
            if(!first_ans && !second_ans)
                pass = false;
        }
        if(!pass)
            cout<<"-1\n";
        else
        {
            for(auto it: checki)
                cout<<it;
            cout<<"\n";
        }
    }
}