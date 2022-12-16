#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,arr[nmax];
bool take[nmax];
priority_queue< pair<int/*value*/,int/*index*/> > pq,emp;
string mess[3]={"pushStack","pushQueue","pushFront"};
string meh[3]={"popStack","popQueue","popFront"};
int SZ[3];


int check[3];


int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>arr[i];
    if(arr[i])pq.push({arr[i],i});
    else
    {
        int rem=pq.size();
        rem=min(rem,3);
        for(int j=0;j<rem;j++)
        {
            take[pq.top().second]=1;
            pq.pop();
        }
        pq=emp;
    }
}
int where=0;
for(int i=1;i<=n;i++)
{
    if(arr[i])
    {
        if(take[i]==0)cout<<"pushBack"<<endl;
        else
        {
            SZ[where]++;
            cout<<mess[where]<<endl;
            where=(where+1)%3;
        }
    }
    else
    {
        int num=(SZ[0]>0)+(SZ[1]>0)+(SZ[2]>0);
        cout<<num;
        for(int j=0;j<3;j++)
        {
            if(SZ[j])
            {
                SZ[j]=0;
                cout<<" "<<meh[j];
            }
        }
        cout<<endl;
    }
}
return 0;
return 0;
}