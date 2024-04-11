#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
pair<int/*pos*/,int/*a[pos]*/> ask(vector<int> output)
{
    printf("?");
    for(auto k:output)printf(" %i",k);

    cout<<endl;
    cout.flush();
    pair<int/*pos*/,int/*a[pos]*/> ret;
    scanf("%i%i",&ret.first,&ret.second);
    return ret;
}
void print(int m)
{
    printf("! %i",m);
    cout.flush();
    exit(0);
}

bool asked[nmax];
int arr[nmax];

pair<int/*pos*/,int/*a[pos]*/> mem[nmax];
vector<int> was[nmax];

int n,k;
int main()
{
    scanf("%i%i",&n,&k);
    if(k==1)print(1);

    for(int t=1;t<=n-k+1;t++)
    {
        vector<int> current={};
        for(int j=1;j<=n&&current.size()<k;j++)
            if(asked[j]==0)current.push_back(j);
        pair<int/*pos*/,int/*a[pos]*/> out=ask(current);
        asked[out.first]=1;
        arr[out.first]=out.second;

        was[t]=current;
        mem[t]=out;
    }

    vector<int> they={};
    for(int i=1;i<=n&&they.size()<2;i++)
        if(asked[i])they.push_back(i);

    if(arr[they[0]]>arr[they[1]])swap(they[0],they[1]);

    int m_=1;
    for(int i=1;i<=n;i++)
        if(asked[i]==0)
        {
            vector<int> current=they;
            for(int j=1;j<=n;j++)
                if(j!=i&&asked[j]==0)current.push_back(j);

            if(ask(current).first==they[1])m_++;
        }

    print(m_);
    return 0;
}