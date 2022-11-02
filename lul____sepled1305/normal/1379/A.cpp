#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        string s ="abacaba";
        string here;
        int n,i,j,k;
        vector<int> index;
        vector<int> hole;
        cin>>n;
        cin>>here;
        int counti[2] = {0,0};
        for(i=0; i<=n-7; i++)
        {
            bool all = true;
            bool par = true;
            int cou=0;
            for(j=0; j<7; j++)
            {
                if(here.at(i+j)!=s.at(j) && here.at(i+j)!='?')
                    all = false,par = false;
                else if(here.at(i+j)!=s.at(j))
                    all = false,cou++;
            }
            if(all)
                counti[0]++;
            if(par)
                counti[1]++, index.push_back(i), hole.push_back(cou);
        }
        if(counti[0]<=1 && counti[0]+counti[1]>=1)
        {
            if(counti[0]==1)
            {
                cout<<"YES\n";
                for(auto it: here)
                {
                    if(it!='?')
                        cout<<it;
                    else
                        cout<<"z";
                }
            }
            else
            {
                bool pass = false;
                for(i=0; i<index.size(); i++)
                {
                    string test = here;
                    for(j=0; j<n; j++)
                    {
                        if(j-index[i] >=0 && j-index[i] <7)
                            test.at(j) = s.at(j-index[i]);
                    }
                    int counti[2] = {0,0};
                    for(j=0; j<=n-7; j++)
                    {
                        bool all = true;
                        bool par = true;
                        for(k=0; k<7; k++)
                        {
                            if(test.at(k+j)!=s.at(k))
                                all = false;
                        }
                        if(all)
                            counti[0]++;
                    }
                    if(counti[0]==1)
                    {
                        cout<<"YES\n";
                        for(auto it: test)
                        {
                            if(it!='?')
                                cout<<it;
                            else
                                cout<<'z';
                        }
                        pass = true;
                        break;
                    }
                }
                if(!pass)
                    cout<<"NO";

            }
            cout<<"\n";
        }
        else
            cout<<"NO\n";
    }
    return 0;
}