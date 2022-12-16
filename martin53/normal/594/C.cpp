#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,k;
pair<int/*value*/,int/*index*/> x[nmax],y[nmax];
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n>>k;
int x1,y1,x2,y2;
for(int i=1;i<=n;i++)
{
    cin>>x1>>y1>>x2>>y2;
    x[i]={x1+x2,i};
    y[i]={y1+y2,i};
}
sort(x+1,x+n+1);
sort(y+1,y+n+1);
long long outp=4e18;

for(int i1=0;i1<=k;i1++)
    for(int i2=0;i2<=k&&i1+i2<=n;i2++)
        for(int j1=0;j1<=k;j1++)
            for(int j2=0;j2<=k&&j1+j2<=n;j2++)
            {
            set<int> active={};
            for(int p=1;p<=i1;p++)active.insert(x[p].second);
            for(int p=1;p<=i2;p++)active.insert(x[n+1-p].second);

            for(int p=1;p<=j1;p++)active.insert(y[p].second);
            for(int p=1;p<=j2;p++)active.insert(y[n+1-p].second);

            if(active.size()<=k)
            {
                int w=max(2,x[n-i2].first-x[i1+1].first);
                int h=max(2,y[n-j2].first-y[j1+1].first);
                if(w%2==1)w++;
                if(h%2==1)h++;
                outp=min(outp,1LL*(w/2)*(h/2));
            }
            }
cout<<outp<<endl;
return 0;
}