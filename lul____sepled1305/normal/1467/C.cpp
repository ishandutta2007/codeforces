#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cap[3];
    long long sum[3],mini[3],cur;
    cin>>cap[0]>>cap[1]>>cap[2];
    int i,j;
    for(j=0;j<3;j++)
    {
        sum[j] = 0, mini[j] = 1e9;
        for(i=0;i<cap[j];i++)
        {
            cin>>cur;
            sum[j]+=cur;
            mini[j] = min(mini[j],cur);
        }
    }
    sort(sum,sum+3);
    sort(mini,mini+3);
    cout<<sum[0]+sum[1]+sum[2] - 2*min(sum[0],mini[1]+mini[0]);
}