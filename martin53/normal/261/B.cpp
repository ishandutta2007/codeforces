#include<bits/stdc++.h>
using namespace std;
const int nmax=55;
map< vector<int>,double> seen;
double rec(vector<int> people,int total,int space)
{
    if(space<0)return -1;
    if(total==0)return 0;
    if(seen.count(people))return seen[people];
    double ans=0;
    for(int j=0;j<=50;j++)
        if(people[j])
        {
        people[j]--;
        ans=ans+(1+rec(people,total-1,space-j))*(people[j]+1)/total;
        people[j]++;
        }
    seen[people]=ans;
    return ans;
}
int n;
vector<int> active;
int p;
int main()
{
scanf("%i",&n);
int x;
for(int i=0;i<=50;i++)active.push_back(0);
for(int i=1;i<=n;i++)
{
    scanf("%i",&x);
    active[x]++;
}
scanf("%i",&p);
printf("%.18f\n",rec(active,n,p));
return 0;
}