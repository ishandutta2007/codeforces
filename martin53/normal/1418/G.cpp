#include<bits/stdc++.h>
using namespace std;

const int nmax=5e5+42;

int n,inp[nmax];

map<int, array<unsigned long long,3> > mem_hsh;

unsigned long long hsh[nmax],pref[nmax];

map<int,int> cnt;

mt19937 rng(42);

array<unsigned long long,3> gen()
{
    array<unsigned long long,3> ret={0,0,0};

    for(int t=0;t<2;t++)
        for(int i=0;i<64;i++)
            ret[t]=ret[t]*2+rng()%2;

    ret[2]=ret[0]^ret[1];

    return ret;
}

map<unsigned long long,int> active;

map<unsigned long long,deque<int> > lst_seen;

int main()
{

    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    /*
    n=5e5;
    for(int i=1;i<=n;i++)inp[i]=1;
    */

    for(int i=1;i<=n;i++)
    {
        if(cnt[inp[i]]==0)
        {
            mem_hsh[inp[i]]=gen();
        }

        hsh[i]=mem_hsh[inp[i]][cnt[inp[i]]%3];

        pref[i]=pref[i-1]^hsh[i];

        //cout<<i<<" -> "<<pref[i]<<endl;

        cnt[inp[i]]++;
    }

    long long outp=0,cur=0;

    int j=0;

    active[0]++;

    for(int i=1;i<=n;i++)
    {
        unsigned long long cur=pref[i];

        lst_seen[inp[i]].push_back(i);

        if(lst_seen[inp[i]].size()==4)
        {
            int cut_to=lst_seen[inp[i]][0];

            //lst_seen[inp[i]].pop_front();

            //cout<<"j= "<<j<<" cut_to= "<<cut_to<<endl;

            while(j<cut_to)
            {
                active[pref[j]]--;

                j++;

                //cout<<j<<" with "<<lst_seen[inp[j]].size()<<endl;

                lst_seen[inp[j]].pop_front();
            }
        }

        outp+=active[cur];

        active[cur]++;

        //cout<<i<<" -> "<<outp<<" "<<j<<" with "<<inp[i]<<endl;
    }

    printf("%lld\n",outp);

    return 0;
}