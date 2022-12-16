#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,inp[nmax],outp[nmax];

vector<int> seen[nmax];

int prv[nmax],nxt[nmax];

stack<int> idle,nxt_st,prv_st;

int pref[nmax];

void make_invalid(int l,int r)
{
    if(l>r)return;

    //cout<<"make invalid "<<l<<" "<<r<<endl;

    pref[l]++;
    pref[r+1]--;
}
void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    prv_st=idle;
    for(int i=1;i<=n;i++)
    {
        while(prv_st.size()&&inp[prv_st.top()]>=inp[i])prv_st.pop();

        if(prv_st.size()==0)prv[i]=0;
        else prv[i]=prv_st.top();

        prv_st.push(i);
    }

    nxt_st=idle;
    for(int i=n;i>=1;i--)
    {
        while(nxt_st.size()&&inp[nxt_st.top()]>=inp[i])nxt_st.pop();

        if(nxt_st.size()==0)nxt[i]=n+1;
        else nxt[i]=nxt_st.top();

        nxt_st.push(i);
    }

    for(int i=1;i<=n;i++)seen[i]={};

    for(int i=1;i<=n;i++)pref[i]=0;

    for(int i=1;i<=n;i++)seen[inp[i]].push_back(i);

    for(int i=1;i<=n;i++)
        if(seen[i].size()==0)
        {
            //i and above cannot be
            make_invalid(1,n-i+1);
        }
        else
        {
            int mx=0;

            for(auto w:seen[i])
            {
                int high=nxt[w]-prv[w]-1;

                mx=max(mx,high);
            }

            //cout<<i<<" -> "<<mx<<endl;
            //high is the maximal valid for i
            make_invalid(mx+1,n-i+1);
        }

    for(int i=1;i<=n;i++)pref[i]=pref[i]+pref[i-1];

    for(int i=1;i<=n;i++)
        if(pref[i]==0)printf("1");
        else printf("0");

    printf("\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}