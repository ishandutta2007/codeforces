/*Ithea is a binary search interactive master.*/
#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> se[k];
        int a,i,j,m;
        for(i=0;i<k;i++)
        {
            cin>>a;
            for(j=0;j<a;j++)
            {
                cin>>m;
                se[i].push_back(m);
            }
        }
        int siz = n,mini=1,maxi=n;
        int ss=1;
        int cur_max;
        cout<<"? "<<n<<" ";
        {
            for(i=1;i<=n;i++)
                cout<<i<<" ";
        }
        cout<<"\n";
        fflush(stdout);
        cin>>cur_max;
        while(siz!=1)
        {
            ss++;
            if(ss==12)
            {
                int mm=0;
                while(true)
                {
                    mm++;
                }
            }
            int mid = mini+(siz-1)/2;
            cout<<"? "<<mid-mini+1<<" ";
            for(i=mini;i<=mid;i++)
            {
                cout<<i<<" ";
            }
            cout<<"\n";
            fflush(stdout);
            int ans;
            cin>>ans;
            if(ans==cur_max)
                maxi = mid;
            else
                mini = mid+1;
            siz = maxi-mini+1;
        }
        int index=1e9;
        for(i=0;i<k;i++)
        {
            for(auto it: se[i])
            {
                if(it == maxi)
                {
                    index = i;
                    break;
                }
            }
        }
        int wow = 77777;
        if(index!=1e9)
        {
            cout<<"? ";
            set<int> sq;
            for(auto it: se[index])
            {
                sq.insert(it);
            }
            int ddd=0;
            for(i=1;i<=n;i++)
            {
                if(sq.count(i)==0)
                {
                    ddd++;
                }
            }
            cout<<ddd<<" ";
            for(i=1;i<=n;i++)
            {
                if(sq.count(i)==0)
                {
                    cout<<i<<" ";
                }
            }
            cout<<"\n";
            fflush(stdout);
            cin>>wow;
        }
        cout<<"! ";
        for(i=0;i<k;i++)
        {
            if(i!=index)
                cout<<cur_max<<" ";
            else
                cout<<wow<<" ";
        }
        cout<<"\n";
        fflush(stdout);
        string s;
        cin>>s;
        if(s!="Correct")
            break;
    }
    return 0;
}