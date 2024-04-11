#include<bits/stdc++.h>
using namespace std;

const int nmax=1000+42;

bool ask(int cur)
{
    cur++;

    cout<<"? "<<cur<<endl;
    cout.flush();

    char ret;
    cin>>ret;

    if(ret=='Y')return 1;
    return 0;
}

void my_reset()
{
    cout<<"R"<<endl;
    cout.flush();
}

bool on[nmax];

int n,k;

int main()
{
    cin>>n>>k;

    for(int i=0;i<n;i++)on[i]=1;

    for(int i=0;i<n;i++)
        if(ask(i))on[i]=0;

    int group=k/2;
    if(group==0)group=1;

    for(int i=0;i<n/group;i++)
        for(int j=i+1;j<n/group;j++)
        {
            my_reset();

            for(int p=0;p<group;p++)
            {
                int cur=i*group+p;

                if(on[cur])ask(cur);
            }

            for(int q=0;q<group;q++)
            {
                int cur=j*group+q;

                if(on[cur])
                {
                    if(ask(cur))on[cur]=0;
                }
            }
        }

    int cnt=0;
    for(int i=0;i<n;i++)
        cnt+=on[i];

    cout<<"! "<<cnt<<endl;
    cout.flush();

    return 0;
}