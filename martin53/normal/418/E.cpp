#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,MX_val=2e5+42,BLOCK_SIZE=320;

int n,arr[nmax];

int q,type[nmax],val[nmax],position[nmax];
int help[nmax*2],id_help=0;

int seen[nmax/BLOCK_SIZE+5][MX_val];//seen[s][t] = how many times we can see t in the first s*BLOCK_SIZE+BLOCK_SIZE-1 elements of arr

int seen_seen[nmax/BLOCK_SIZE+5][nmax];//seen_seen[s][t] = how many times we can see t in the first s*BLOCK_SIZE+BLOCK_SIZE-1 elements of seen

int ask_seen(int value,int up_to_position)
{
    int ret=0,current_group=up_to_position/BLOCK_SIZE;

    if(current_group)ret=ret+seen[current_group-1][value];

    for(int i=max(1,current_group*BLOCK_SIZE);i<=up_to_position;i++)
        ret=ret+(arr[i]==value);

    return ret;
}
int ask_seen_seen(int up_to_position)
{
    int value=ask_seen(arr[up_to_position],up_to_position);

    int ret=0,current_group=up_to_position/BLOCK_SIZE;

    if(current_group)ret=ret+seen_seen[current_group-1][value];

    for(int i=max(1,current_group*BLOCK_SIZE);i<=up_to_position;i++)
        ret=ret+(ask_seen(arr[i],i)==value);

    return ret;

}
void upd(int position,int value,int with)
{
    //cout<<"upd "<<position<<" "<<value<<" "<<with<<endl;

    int current_group=position/BLOCK_SIZE;

    int was=0;
    if(current_group)was=seen[current_group-1][value];

    for(int i=position/BLOCK_SIZE;i*BLOCK_SIZE<=n;i++)
    {
        int is=seen[i][value];

        seen[i][value]+=with;
        if(with==1)
        {
            seen_seen[i][is+1]++;
        }
        else
        {
            seen_seen[i][is]--;
        }
    }
}

void update(int position,int val)
{
    upd(position,arr[position],-1);
    upd(position,val,1);
    arr[position]=val;
    /*
    for(int i=1;i<=n;i++)cout<<arr[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++)cout<<ask_seen(arr[i],i)<<" ";cout<<endl;
    for(int i=1;i<=n;i++)cout<<ask_seen_seen(i)<<" ";cout<<endl;
    cout<<"---"<<endl;
    */
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&arr[i]);
        id_help++;
        help[id_help]=arr[i];
    }

    scanf("%i",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%i%i%i",&type[i],&val[i],&position[i]);
        if(type[i]==1)
        {
            id_help++;
            help[id_help]=val[i];
        }
    }

    sort(help+1,help+id_help+1);

    for(int i=1;i<=n;i++)
        arr[i]=lower_bound(help+1,help+id_help+1,arr[i])-help;

    for(int i=1;i<=q;i++)
    {
        if(type[i]==1)val[i]=lower_bound(help+1,help+id_help+1,val[i])-help;
    }

    for(int group=0;group*BLOCK_SIZE<=n;group++)
    {
        if(group)
        {
            for(int j=0;j<MX_val;j++)
                seen[group][j]=seen[group-1][j];
        }

        for(int i=group*BLOCK_SIZE;i<=group*BLOCK_SIZE+BLOCK_SIZE-1&&i<=n;i++)
            seen[group][arr[i]]++;
    }

    for(int group=0;group*BLOCK_SIZE<=n;group++)
    {
        if(group)
        {
            for(int j=0;j<nmax;j++)
                seen_seen[group][j]=seen_seen[group-1][j];
        }

        for(int i=group*BLOCK_SIZE;i<=group*BLOCK_SIZE+BLOCK_SIZE-1&&i<=n;i++)
            seen_seen[group][ask_seen(arr[i],i)]++;
    }

    for(int i=1;i<=q;i++)
    {
        if(type[i]==1)
        {
            update(position[i],val[i]);
        }
        else
        {
            if(val[i]==1)printf("%i\n",help[arr[position[i]]]);
            else if(val[i]%2==0)printf("%i\n",ask_seen(arr[position[i]],position[i]));
            else printf("%i\n",ask_seen_seen(position[i]));
        }
    }
    return 0;
}