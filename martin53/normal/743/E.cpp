#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+42,NUM=8;
int n,arr[nmax];
int where[nmax][nmax][NUM];
int can[nmax][1<<NUM];
int SZ;
bool add[1<<NUM];
int rec(int pos,int state)
{
    if(state==0)return 1;
    if(pos>=n)return 0;
    if(can[pos][state]!=-1)return can[pos][state];
    bool ok=0;
    for(int number=0;number<NUM;number++)
        if((state&(1<<number)))
        {
        if(where[pos][SZ+add[number]][number]!=-1)ok=ok|rec(where[pos][SZ+add[number]][number],state-(1<<number));
        }
    can[pos][state]=ok;
    //cout<<pos<<" "<<state<<" "<<can[pos][state]<<endl;
    return ok;
}
bool possible(int k)
{
    SZ=k;
    //cout<<"SZ= "<<SZ<<endl;
    memset(can,-1,sizeof(can));
    return rec(0,(1<<NUM)-1);
}
vector<int> seen[NUM];
int main()
{
cin>>n;
for(int i=0;i<n;i++)
{
cin>>arr[i];
arr[i]--;
}

memset(where,-1,sizeof(where));
for(int i=n-1;i>=0;i--)
{
    seen[arr[i]].push_back(i);
    for(int skip=0;skip<=n;skip++)
        for(int number=0;number<NUM;number++)
        {
            if(skip==0)where[i][skip][number]=i;
            else if(seen[number].size()>=skip)where[i][skip][number]=seen[number][seen[number].size()-skip]+1;
            //if(where[i][skip][number]!=-1)cout<<i<<" "<<skip<<" "<<number<<" "<<where[i][skip][number]<<endl;
        }
    //cout<<endl;
}

int ok=0,not_ok=n/NUM+1;
while(not_ok-ok>1)
{
    int av=(ok+not_ok)/2;
    if(possible(av))ok=av;
    else not_ok=av;
}
//cout<<ok<<endl;
int ans=NUM*ok,m=0;
for(int mask=0;mask<(1<<NUM);mask++)
{
    for(int j=0;j<NUM;j++)
        add[j]=(mask&(1<<j));
    //cout<<mask<<" -> ";for(int i=0;i<NUM;i++)cout<<add[i]<<" ";cout<<endl;
    if(possible(ok))
    {
        m=max(m,__builtin_popcount(mask));
    }
}
//cout<<ok<<endl;
cout<<ans+m<<endl;
return 0;
}