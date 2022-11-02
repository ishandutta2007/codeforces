#include<bits/stdc++.h>
using namespace std;
int i,j,k,t,n,maxi=-1000,fucking;
int ar[200005];
vector<int> arr[205];
int fuck[205][3];

int bs(int mini, int ma, int tar, int arrr)
{
    int mid=(mini+ma)/2;
    if(mini==mid)
    {
        if(arr[arrr][mini]>tar)
            return -1;
        else if (arr[arrr][ma]<=tar)
            return ma;
        else
            return mini;
    }
    else
    {
        if(arr[arrr][mid]<=tar)
            return bs(mid,ma,tar,arrr);
        else
            return bs(mini,mid-1,tar,arrr);
    }
}

int main()
{
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        maxi=1;
        for(j=1;j<201;j++)
        {
            while(!arr[j].empty())
            {
                arr[j].pop_back();
            }
        }

        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&k);
            ar[j] = k;
        }
        for(j=0;j<n;j++)
        {
            arr[ar[j]].push_back(j);
        }
        for(j=0;j<201;j++)
        {
            fuck[j][0] = -1;
            fuck[j][1] = arr[j].size()-1;
        }
        for(j=0;j<n;j++)
        {
            int cur,checki,rchecki,thisv,localmax=0;
            cur = ar[j];
            fuck[cur][0]++;
            checki = arr[cur][fuck[cur][0]];
            if(arr[cur].size()>=2*(fuck[cur][0]+1))
            {
                thisv = 2*(fuck[cur][0]+1);
                rchecki = arr[cur][arr[cur].size()-1-fuck[cur][0]];
                //cout<<rchecki<<" "<<arr[cur].size()-fuck[cur][0]<<" "<<arr[cur].size()<<" ";
                for(k=1;k<201;k++)
                {
                    if(!arr[k].empty())
                    {
                        fucking = bs(0,arr[k].size()-1,rchecki-1,k);
                        if(fucking - fuck[k][0] > localmax)
                        {
                            localmax = fucking - fuck[k][0];
                            //printf("HEYY %d %d %d %d %d\n",cur,k,localmax,fucking,fuck[k][0]);
                        }
                    }
                }
                if(thisv+localmax > maxi)
                {
                    maxi = thisv+localmax;
                }
            }
            //printf("%d %d %d \n",cur,k,localmax);
        }
        printf("%d\n",maxi);
        //cout<<arr[1][0]<<arr[1][1]<<arr[1][2]<<arr[1][3]<<"\n";
    }
    return 0;
}