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
        for(i=0;i<n;i++)
        {
            fi.push_back(a.at(i)-'0');
            se.push_back(b.at(i)-'0');
        }
        for(i=n-1;i>=0;i--)
        {
            if(fi[i]!=se[i])
            {
                if(fi[0]!=se[i])
                {
                    flip.push_back(i);
                    int arr[i+1];
                    for(j=0;j<i+1;j++)
                    {
                        arr[j] = fi[i-j]^1;
                    }
                    for(j=0;j<i+1;j++)
                    {
                        fi[j] = arr[j];
                    }
                }
                else
                {
                    flip.push_back(0);
                    fi[0] = fi[0]^1;
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