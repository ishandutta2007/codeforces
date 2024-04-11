#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42,MX=(1<<21)+42;
int n,inp[nmax];

int nums[nmax],now[nmax],seen[MX];

vector<int> active;

int bits=0;

void update(int pos,int number)
{
    if(pos>=bits)
    {
        seen[number]++;
        return;
    }
    if(seen[number]>=2)return;

    update(pos+1,number);
    if(((1<<pos)&number))update(pos+1,number-(1<<pos));
}
bool can(int b)
{
    bits++;

    for(int i=1;i<=n;i++)
        now[i]=nums[i];

    for(int i=1;i<=n;i++)
    {
        if(((1<<b)&inp[i]))
        {
            now[i]+=(1<<(bits-1));
        }
    }

    //cout<<b<<" -> ";for(int i=1;i<=n;i++)cout<<now[i]<<" ";cout<<endl;

    memset(seen,0,sizeof(seen));
    int MX=(1<<(bits))-1;

    for(int i=n;i>=1;i--)
    {
        if(seen[MX-now[i]]>=2)return 1;
        update(0,now[i]);
    }
    return 0;
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
        scanf("%i",&inp[i]);


    int output=0;
    for(int i=20;i>=0;i--)
    {
        if(can(i))
        {
            output=output+(1<<i);
            for(int j=1;j<=n;j++)
                nums[j]=now[j];
        }
        else bits--;
    }

    printf("%i\n",output);
}