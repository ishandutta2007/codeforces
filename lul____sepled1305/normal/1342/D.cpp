#pragma GCC optimize "-O3"
#include<bits/stdc++.h>
using namespace std;
int t,i,n,k,ans,cur,j,mini;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ans = 0;
    mini = 1e9;
    int counti =0;
    cin>>n>>k;
    vector<int> con;
    vector<int> printt [n];
    int arr[k+1];
    for(i=0;i<k+1;i++)
        arr[i] = 0;
    for(i=0;i<n;i++)
    {
        cin>>j;
        arr[j]++;
    }
    for(i=0;i<k;i++)
    {
        cin>>j;
        con.push_back(j);
    }
    int ss=0;
    int pointer = 0;
    for(i=k;i>0;i--)
    {
        bool done = false;
        if(i!=k && con[i-1]!=con[i])
            pointer=0;
        while(!done)
        {

            if(arr[i] == 0)
            {
                done = true;
                break;
            }

            if(pointer > ss)
            {
                ss++;
                continue;
            }

            if(printt[pointer].size() >= con[i-1] && counti!=n)
            {
                pointer++;
                continue;
            }

            while(printt[pointer].size() < con[i-1] && arr[i]>0)
            {
                printt[pointer].push_back(i);
                arr[i]--;
                counti++;
            }
        }
    }
    cout<<ss+1<<"\n";
    for(i=0;i<ss+1;i++)
    {
        cout<<printt[i].size()<<" ";
        for(auto it: printt[i])
            cout<<it<<" ";
        cout<<"\n";
    }
    return 0;
}