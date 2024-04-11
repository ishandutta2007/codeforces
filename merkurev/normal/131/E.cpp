#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
int cor[2][100005];
int r[10];
int ml[100005],Ml[100005],mr[100005],Mr[100005],ma[200005],Ma[200005],mb[200005],Mb[200005];
int main(){
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        cor[0][i]=x;
        cor[1][i]=y;
        if (ml[y]==0 || x<ml[y]) ml[y]=x;
        Ml[y]=max(Ml[y],x);
        if (mr[x]==0 || y<mr[x]) mr[x]=y;
        Mr[x]=max(Mr[x],y);
        if (ma[x-y+n]==0 || x<ma[x-y+n]) ma[x-y+n]=x;
        Ma[x-y+n]=max(Ma[x-y+n],x);
        if (mb[x+y]==0 || x<mb[x+y]) mb[x+y]=x;
        Mb[x+y]=max(Mb[x+y],x);
    }
    for (int i=0;i<m;i++)
    {
        int x=0;
        //cout<<cor[0][i]<<" "<<cor[1][i]<<"     "<<ml[cor[1][i]]<<" "<<Ml[cor[1][i]]<<"    "<<mr[cor[0][i]]<<" "<<Mr[cor[0][i]]<<endl;
        if (cor[0][i]>ml[cor[1][i]]) x++;
        if (cor[0][i]<Ml[cor[1][i]]) x++;
        if (cor[1][i]>mr[cor[0][i]]) x++;
        if (cor[1][i]<Mr[cor[0][i]]) x++;
        if (cor[0][i]>ma[cor[0][i]-cor[1][i]+n]) x++;
        if (cor[0][i]<Ma[cor[0][i]-cor[1][i]+n]) x++;
        if (cor[0][i]>mb[cor[0][i]+cor[1][i]]) x++;
        if (cor[0][i]<Mb[cor[0][i]+cor[1][i]]) x++;
        r[x]++;
    }
    for (int i=0;i<9;i++)
        cout<<r[i]<<" ";
    return 0;
}