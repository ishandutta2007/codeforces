#include<bits/stdc++.h>
using namespace std;
const int nmax=1.5e5,SZ=400;
int n;
int back_pop[SZ];
int arr[SZ][SZ];/*pop back_pop[i], then push arr[i][1],arr[i][2]...arr[i][arr[i][0]]*/
int C;
pair<int/*type*/,int/*value*/> operations[nmax];
void recalc(int ind)
{
    int group=ind/C;
    int l=group*C,r=group*C+C-1;
    int pos=0;
    back_pop[group]=0;
    arr[group][0]=0;
    for(int i=l;i<=r;i++)
        if(operations[i].first==0)
        {
            if(pos)pos--;
            else back_pop[group]++;
        }
        else if(operations[i].first==1)
        {
            pos++;
            arr[group][pos]=operations[i].second;
        }
    //cout<<group<<" has: ";for(int i=1;i<=pos;i++)cout<<arr[group][i]<<" ";cout<<"and "<<back_pop[group]<<endl;
    arr[group][0]=pos;
}
pair<int/*group*/,int/*how many*/> help[SZ];
int main()
{
scanf("%i",&n);
int p,t,x;
C=sqrt(n);
int MAX=n/C;
memset(operations,-1,sizeof(operations));
for(int i=1;i<=n;i++)
{
    scanf("%i%i",&p,&t);
    if(t==0)operations[p]={0,t};
    else
    {
        scanf("%i",&x);
        operations[p]={1,x};
    }
    recalc(p);
    int pos=0,bp;
    for(int i=0;i<=MAX;i++)
    {
        bp=back_pop[i];
        while(pos&&bp)
        {
            //cout<<pos<<" with "<<help[pos].first<<" "<<help[pos].second<<" and "<<i<<" with "<<bp<<endl;
            if(bp<=help[pos].second)
            {
                help[pos].second-=bp;
                bp=0;
            }
            else
            {
                bp-=help[pos].second;
                help[pos].second=0;
                pos--;
            }

        }
        while(pos&&help[pos].second==0)pos--;
        if(arr[i][0])
        {
        pos++;
        help[pos]={i,arr[i][0]};
        }
        //cout<<i<<" "<<pos<<" -> "<<
    }
    if(pos==0)printf("-1\n");
    else printf("%i\n",arr[help[pos].first][help[pos].second]);
}
return 0;
}