#include<bits/stdc++.h>
using namespace std;

const int nmax=2000+42;

int n;
pair<int,int> inp[nmax];

long long area(int a,int b,int c)
{
    long long x1=inp[b].first-inp[a].first,y1=inp[b].second-inp[a].second;
    long long x2=inp[c].first-inp[b].first,y2=inp[c].second-inp[b].second;

    return x1*y2-x2*y1;
}

int root;

int quad(int id)
{
    if(inp[id].first>=inp[root].first&&inp[id].second>=inp[root].second)return 1;
    if(inp[id].first<inp[root].first&&inp[id].second>=inp[root].second)return 2;

    if(inp[id].first<inp[root].first&&inp[id].second<inp[root].second)return 3;
    return 4;
}

bool cmp(int a,int b)
{
    if(quad(a)!=quad(b))return quad(a)<quad(b);
    return area(a,root,b)<0;
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i%i",&inp[i].first,&inp[i].second);

    long long outp=0;
    for(int i=1;i<=n;i++)
    {
        root=i;

        vector< int > active={};
        for(int j=1;j<=n;j++)
            if(i!=j)active.push_back(j);

        sort(active.begin(),active.end(),cmp);
        /*
        cout<<"root= "<<root<<endl;
        for(auto w:active)cout<<w<<" "<<inp[w].first-inp[root].first<<" "<<inp[w].second-inp[root].second<<endl;
        cout<<"---"<<endl;
        */
        int pos=1;

        int SZ=active.size();

        for(int j=0;j<SZ;j++)
        {
            if(pos==j)pos=(j+1)%SZ;

            while(pos!=j&&area(active[j],root,active[pos])<0)
            {
                pos=(pos+1)%SZ;
            }

            int high;

            if(j==pos)high=0;
            else if(j<pos)high=pos-1-j;
            else high=pos+(SZ-1-j);

            int low=n-2-high;

            /*
            cout<<i<<" "<<j<<" "<<high<<" "<<low<<endl;

            cout<<"high= "<<high<<" low= "<<low<<" pos= "<<pos<<" j= "<<j<<endl;
            */
            long long cur=high*(high-1)/2;
            cur=cur*low*(low-1)/2;
            cur=cur*2;

            outp+=cur;
            /*
            int actual_high=0,actual_low=0;

            cout<<"high: ";

            for(int k=1;k<=n;k++)
                if(k!=i&&k!=active[j])
                {
                    if(area(i,k,active[j])<0)
                    {
                        cout<<k<<" ";
                        actual_high++;
                    }
                    else actual_low++;
                }

            cout<<endl;

            high=actual_high;
            low=actual_low;

            cout<<"actual: "<<actual_high<<" "<<actual_low<<endl;

            //assert(high==actual_high&&low==actual_low);

            cout<<"----"<<endl;
            */
        }
    }
    outp=outp/4;

    printf("%lld\n",outp);

    return 0;
}