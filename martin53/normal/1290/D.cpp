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

bool used[nmax][nmax];

int group;

bool make_path()
{
    vector<int> path={};

    for(int i=0;i<n/group;i++)
    {
        vector<int> path={i};

        int cur=i;

        for(int j=i+1;j<n/group;j++)
            if(used[cur][j]==0)
            {
                used[cur][j]=1;
                path.push_back(j);
                cur=j;
            }

        //cout<<"path: ";for(auto w:path)cout<<w<<" ";cout<<endl;

        if(path.size()>1)
        {
            my_reset();

            for(auto i:path)
            {
                for(int p=0;p<group;p++)
                {
                    int cur=i*group+p;

                    if(on[cur])
                    {
                        if(ask(cur))on[cur]=0;
                    }
                }
            }

            return 1;
        }
    }
    return 0;
}
int main()
{
    cin>>n>>k;

    for(int i=0;i<n;i++)on[i]=1;

    group=k/2;
    if(group==0)group=1;

    while(make_path());

    int cnt=0;
    for(int i=0;i<n;i++)
        cnt+=on[i];

    cout<<"! "<<cnt<<endl;
    cout.flush();

    return 0;
}