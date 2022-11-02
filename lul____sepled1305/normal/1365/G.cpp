#include<bits/stdc++.h>
using namespace std;
string mask[2000];
int counti,n,i,j;
string cur;
long long bitmask[15];

void makeMask(int depth, int black)
{
    depth++;

    cur.push_back('0');
    if(depth==13)
    {
        if(black == 7)
        {
            mask[counti] = cur;
            counti++;
        }
    }
    else
    {
        makeMask(depth,black);
    }
    cur.pop_back();
    cur.push_back('1');
    black++;
    if(depth==13)
    {
        if(black == 7)
        {
            mask[counti] = cur;
            counti++;
        }
    }
    else
    {
        makeMask(depth,black);
    }
    cur.pop_back();
}

int main()
{
    makeMask(0,0);
    cin>>n;
    for(i=0;i<13;i++)
    {
        int curi=0;
        for(j=0;j<n;j++)
        {
            if(mask[j].at(i)=='1')
                curi++;
        }
        if(curi>0)
        {
            cout<<"? "<<curi<<" ";
            for(j=0;j<n;j++)
            {
                if(mask[j].at(i)=='1')
                    cout<<j+1<<" ";
            }
            cout<<"\n";
            fflush(stdout);
            cin>>bitmask[i];
        }
    }
    cout<<"! ";
    for(i=0;i<n;i++)
    {
        long long curi=0;
        for(j=0;j<13;j++)
        {
            if(mask[i].at(j)=='0')
                curi = curi | bitmask[j];
        }
        cout<<curi<<" ";
    }
    cout<<"\n";
    fflush(stdout);
}