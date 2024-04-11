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
        int n,i,counti=0;
        cin>>n;
        int a[n];
        bool used[n];
        deque<int> de[n];
        for(i=0;i<n;i++)
            cin>>a[i],used[i]=false;
        cout<<2*n<<"\n";
        for(i=0;i<n;i++)
        {
            if(a[i]<n)
                used[a[i]]=true;
            if(a[i]<n)
                de[a[i]].push_back(i);
        }
        int prin = 0;
        int pointer = 0;
        for(i=0;i<n;i++)
        {
            while(!de[pointer].empty())
                pointer++;
            if(a[i]>=n || (a[i]<n && de[a[i]].size()>1))
            {
                cout<<i+1<<" ";
                prin++;
                de[pointer].push_back(i);
                if(a[i]<n)
                    de[a[i]].pop_front();
                a[i] = pointer;
            }
        }
        for(i=0;i<n;i++)
        {
            if(a[i]!=i)
            {
                cout<<i+1<<" ";
                prin++;
                int cur = a[i];
                int prv = i;
                a[i] = n;
                while(a[cur]!=n)
                {
                    cout<<cur+1<<" ";
                    int im = cur;
                    cur = a[cur];
                    a[im] = im;
                    prv = im;
                    prin++;
                }
                cout<<i+1<<" ";
                prin++;
            }
        }
        while(prin<2*n)
            cout<<n<<" ",prin++;
        cout<<"\n";
    }
    return 0;
}