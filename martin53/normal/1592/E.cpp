#include<bits/stdc++.h>
using namespace std;

const int nmax=(1<<20)+42;

int n,inp[nmax],inp_help[nmax];

int pref_xor[nmax];

int outp=0;

int seen[nmax];

void solve(int le,int ri)
{
    //cout<<"le= "<<le<<" ri= "<<ri<<endl;

    for(int diff=0;diff<2;diff++)
    {
        for(int i=le-1+diff;i<=ri;i=i+2)
        {
            if(seen[pref_xor[i]]!=-1)
            {
                //cout<<i<<" "<<seen[pref_xor[i]]<<endl;
                outp=max(outp,i-seen[pref_xor[i]]);
            }
            else seen[pref_xor[i]]=i;
        }

        for(int i=le-1+diff;i<=ri;i=i+2)
            seen[pref_xor[i]]=-1;
    }
}

int main()
{
    memset(seen,-1,sizeof(seen));

    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int bit=19;bit>=0;bit--)
    {
        //cout<<"bit= "<<bit<<endl;

        for(int i=1;i<=n;i++)
            if((inp[i]&(1<<(bit+1))))inp_help[i]+=(1<<(bit+1));

        for(int i=1;i<=n;i++)pref_xor[i]=pref_xor[i-1]^inp_help[i];

        for(int i=1;i<=n;i++)
            if((inp[i]&(1<<bit)))
        {
            int j=i;

            while(j<=n&&(inp[j]&(1<<bit)))j++;

            j--;

            solve(i,j);

            i=j;
        }
    }

    printf("%i\n",outp);
    return 0;
}