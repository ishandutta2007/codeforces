#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,inp[nmax];

int mem[nmax][4];

int l,r;

int mem_three[nmax][3];

void update(int pos,int val_2,int val_3)
{
    if(mem_three[pos][0]==0||val_3<mem_three[pos][2])
    {
        mem_three[pos][0]=pos;
        mem_three[pos][1]=val_2;
        mem_three[pos][2]=val_3;
    }
}
int query()
{
    scanf("%i%i",&l,&r);

    if(mem[l][0]&&mem[l][3]<=r)
    {
        printf("4\n");
        printf("%i %i %i %i\n",mem[l][0],mem[l][1],mem[l][2],mem[l][3]);
        return 4;
    }

    if(mem_three[l][0]&&mem_three[l][2]<=r)
    {
        printf("3\n");
        printf("%i %i %i\n",mem_three[l][0],mem_three[l][1],mem_three[l][2]);
        return 3;
    }

    printf("0\n\n");
    return 0;
}

bool valid(int i,int j,int k)
{
    if(inp[i]<=inp[j]&&inp[j]<=inp[k])return 0;
    if(inp[i]>=inp[j]&&inp[j]>=inp[k])return 0;
    return 1;
}
int dumb()
{
    for(int i=l;i<=r;i++)
        for(int j=i+1;j<=r;j++)
            for(int k=j+1;k<=r;k++)
                for(int p=k+1;p<=r;p++)
                {
                    if(valid(i,j,p)&&valid(i,j,k)&&valid(j,k,p)&&valid(i,k,p))return 4;
                }

    for(int i=l;i<=r;i++)
        for(int j=i+1;j<=r;j++)
            for(int k=j+1;k<=r;k++)
                if(valid(i,j,k))return 3;

    return 0;
}

pair<int,int> mem_left[nmax],mem_right[nmax];

int start_left[nmax],start_right[nmax];

stack<int> mini,maxi,idle;

bool check(int id,int a,int b,int c,int d)
{
    int help[4]={a,b,c,d};
    sort(help,help+4);

    for(int i=1;i<4;i++)
        if(help[i-1]==help[i])return 0;

    for(int i=0;i<4;i++)
        for(int j=i+1;j<4;j++)
            for(int k=j+1;k<4;k++)
            {
                if(inp[help[i]]<=inp[help[j]]&&inp[help[j]]<=inp[help[k]])return 0;
                if(inp[help[i]]>=inp[help[j]]&&inp[help[j]]>=inp[help[k]])return 0;
            }

    for(int j=0;j<4;j++)
        mem[id][j]=help[j];
    return 1;
}

int high_left[nmax],high_right[nmax];
int low_left[nmax],low_right[nmax];

int main()
{
    int q;

    scanf("%i%i",&n,&q);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=n;i>=1;i--)
    {
        while(mini.size()&&inp[i]<=inp[mini.top()])mini.pop();
        while(maxi.size()&&inp[i]>=inp[maxi.top()])maxi.pop();

        if(mini.size())low_right[i]=mini.top();
        if(maxi.size())high_right[i]=maxi.top();

        if(mini.size()&&maxi.size())
        {
            mem_left[i]={mini.top(),maxi.top()};
            start_left[i]=max(mini.top(),maxi.top());
        }

        mini.push(i);
        maxi.push(i);
    }

    mini=idle;
    maxi=idle;

    for(int i=1;i<=n;i++)
    {
        while(mini.size()&&inp[i]<=inp[mini.top()])mini.pop();
        while(maxi.size()&&inp[i]>=inp[maxi.top()])maxi.pop();

        if(mini.size())low_left[i]=mini.top();
        if(maxi.size())high_left[i]=maxi.top();

        if(mini.size()&&maxi.size())
        {
            mem_right[i]={mini.top(),maxi.top()};
            start_right[i]=min(mini.top(),maxi.top());
        }

        mini.push(i);
        maxi.push(i);
    }

    for(int mid=1;mid<=n;mid++)
    {
        if(low_left[mid]&&low_right[mid])
            update(low_left[mid],mid,low_right[mid]);

        if(high_left[mid]&&high_right[mid])
            update(high_left[mid],mid,high_right[mid]);
    }
    /*
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" -> "<<start_left[i]<<" "<<start_right[i]<<endl;
    }
    */

    vector<int> valid_j={};
    for(int j=1;j<=n;j++)
        if(start_right[j])valid_j.push_back(j);

    for(int i=1;i<=n;i++)
        if(start_left[i])
    {
        int pos=lower_bound(valid_j.begin(),valid_j.end(),start_left[i]+1)-valid_j.begin();

        //for(int j=start_left[i]+1;j<=n;j++)
        for(int t=pos;t<valid_j.size();t++)
        {
            int j=valid_j[t];

            if(i<start_right[j])
            {
                int arr[4]={mem_left[i].first,mem_left[i].second,mem_right[j].first,mem_right[j].second};

                for(int p=0;p<4;p++)
                    for(int q=p+1;q<4;q++)
                        if(check(i,i,j,arr[p],arr[q]))p=4,q=4;

                //cout<<"found "<<i<<endl;

                assert(mem[i][0]);
                break;
            }
        }
    }

    for(int i=n;i>=1;i--)
        if(mem[i+1][0])
        {
            if(mem[i][0]==0||mem[i][3]>mem[i+1][3])
            {
                mem[i][0]=mem[i+1][0];
                mem[i][1]=mem[i+1][1];
                mem[i][2]=mem[i+1][2];
                mem[i][3]=mem[i+1][3];
            }
        }

    for(int i=n;i>=1;i--)
        if(mem_three[i+1][0])
        {
            if(mem_three[i][0]==0||mem_three[i][2]>mem_three[i+1][2])
            {
                mem_three[i][0]=mem_three[i+1][0];
                mem_three[i][1]=mem_three[i+1][1];
                mem_three[i][2]=mem_three[i+1][2];
            }
        }

    for(int i=1;i<=q;i++)
        query();

    /*
    for(l=1;l<=n;l++)
        for(r=l+2;r<=n;r++)
    {
        int mem_q=query();
        int mem_d=dumb();

        cout<<mem_q<<" "<<mem_d<<" "<<l<<" "<<r<<endl;

        assert(mem_q==mem_d);
    }
    */
    return 0;
}