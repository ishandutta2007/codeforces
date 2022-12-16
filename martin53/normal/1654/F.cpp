#include<bits/stdc++.h>
using namespace std;

const int nmax=(1<<18)+42;

int pwr;
int n;
string inp;

int order[nmax];

pair< pair<int,int> , int > cur[nmax];

void solve()
{
    cin>>pwr;

    n=(1<<pwr);

    cin>>inp;

    for(int i=0;i<n;i++)
        order[i]=inp[i]-'a';

    for(int j=1;j<=pwr;j++)//sort (1<<j)
    {
        for(int i=0;i<n;i++)
        {
            cur[i]={{order[i],order[i^(1<<(j-1))]},i};
        }

        sort(cur,cur+n);

        int id=0;

        for(int i=0;i<n;i++)
        {
            id++;

            int j=i;

            while(j<n&&cur[i].first==cur[j].first)
            {
                order[cur[j].second]=id;
                j++;
            }

            j--;

            i=j;
        }
    }

    int x=0;

    for(int i=0;i<n;i++)
        if(order[x]>order[i])x=i;

    for(int i=0;i<n;i++)
        cout<<inp[i^x];
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    solve();

    return 0;
}