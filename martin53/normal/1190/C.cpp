#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,k,inp[nmax];

int pref[nmax];

int ask(int l,int r)
{
    if(l>r)return 0;
    return pref[r]-pref[l-1];
}
bool first_win()
{
    for(int l=1;l+k-1<=n;l++)
    {
        int r=l+k-1;

        int other=ask(1,l-1)+ask(r+1,n);
        int should=l-1-1+1+n-(r+1)+1;

        if(other==0||other==should)return 1;
    }
    return 0;
}

vector<int> seen[2];
int ask_first(int l,int r,int type)
{
    if(l>r)return -1;
    int p=lower_bound(seen[type].begin(),seen[type].end(),l)-seen[type].begin();
    if(p==seen[type].size())return -1;
    if(seen[type][p]>r)return -1;
    return seen[type][p];
}

int ask_last(int l,int r,int type)
{
    if(l>r)return -1;
    int p=upper_bound(seen[type].begin(),seen[type].end(),r)-seen[type].begin();
    p--;
    if(p<0)return -1;
    if(seen[type][p]<l)return -1;
    return seen[type][p];
}
bool second_win()
{
    for(int l=1;l+k-1<=n;l++)
    {
        int r=l+k-1;

        //colour 0

        int p=ask_first(1,l-1,1);
        if(p==-1)p=ask_first(r+1,n,1);

        int q=ask_last(r+1,n,1);
        if(q==-1)q=ask_last(1,l-1,1);

        if(q-p+1>k)return 0;

        //colour 1

        p=ask_first(1,l-1,0);
        if(p==-1)p=ask_first(r+1,n,0);

        q=ask_last(r+1,n,0);
        if(q==-1)q=ask_last(1,l-1,0);

        if(q-p+1>k)return 0;
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        inp[i]=c-'0';
        pref[i]=pref[i-1]+inp[i];
        seen[inp[i]].push_back(i);
    }

    if(first_win())
    {
        printf("tokitsukaze\n");
        return 0;
    }

    if(second_win())
    {
        printf("quailty\n");
        return 0;
    }


    printf("once again\n");
    return 0;
}