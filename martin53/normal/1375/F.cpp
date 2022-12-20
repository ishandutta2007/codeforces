#include<bits/stdc++.h>
using namespace std;

pair<long long,int> inp[4];

int apply(long long add)
{
    int pos;
    cin>>pos;

    for(int i=1;i<=3;i++)
        if(inp[i].second==pos)
        {
            inp[i].first+=add;
            return i;
        }

    assert(0==1);
}
int main()
{
    long long a,b,c;

    for(int i=1;i<=3;i++)
    {
        cin>>inp[i].first;
        inp[i].second=i;
    }

    cout<<"First"<<endl;
    cout.flush();

    while(1)
    {

    sort(inp+1,inp+3+1);

    long long add=2*inp[3].first-inp[1].first-inp[2].first;

    cout<<add<<endl;
    cout.flush();

    int mem=apply(add);

    if(mem==1)
    {
        cout<<inp[3].first-inp[2].first<<endl;
        cout.flush();

        int cur;
        cin>>cur;
        return 0;
    }

    if(mem==2)
    {
        cout<<inp[3].first-inp[1].first<<endl;
        cout.flush();

        int cur;
        cin>>cur;
        return 0;
    }

    }

    return 0;
}