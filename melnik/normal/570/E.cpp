#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;
vector <int> kol[501][501];
queue <pair <int,int> > v;
int inf=1e9+7;
int i[501][501];

void initialization1(int n,int m,int x,int y){
    if (y!=0)
        for (int z=y-1;z>=0;z--) v.push(make_pair(x,z));
    while (x>0&&y<m){
        v.push(make_pair(x-1,y));
        kol[x][y].push_back(1);
        x--;
        y++;
    }
    if (y<m&&x==0) kol[x][y].push_back(1);
}

void initialization2(int n,int m,int x,int y){
    if (y!=0)
        for (int z=y-1;z>=0;z--) v.push(make_pair(x,z));
    while (x>0&&y<m){
        v.push(make_pair(x-1,y));
        if (i[x][y]==i[x+1][y]) kol[x][y].push_back(1); else kol[x][y].push_back(0);
        if (i[x][y]==i[x][y+1]) kol[x][y].push_back(1); else kol[x][y].push_back(0);
        x--;
        y++;
    }
    if (y<m&&x==0) {
        if (i[x][y]==i[x+1][y]) kol[x][y].push_back(1); else kol[x][y].push_back(0);
        if (i[x][y]==i[x][y+1]) kol[x][y].push_back(1); else kol[x][y].push_back(0);
    }
}

void _begin(int n, int m){
    if ((n+m)%2==0) initialization1(n,m,min(n-1,(n+m)/2-1),max(0,(m-n)/2)); else
        initialization2(n,m,min(n-1,(n+m)/2-1),max(0,(m-n)/2));
}


void re_count(int x,int y){
    if (x-1>=0) v.push(make_pair(x-1,y));
    int k=kol[x+1][y].size(),l,dx=k+1,dy=0;
    kol[x][y].push_back(0);
    for (l=0;l<k;l++){
        kol[x][y].push_back(0);
        if (kol[x+1][y][l]!=0) {
            if (i[x][y]==i[x+dx][y+dy]) kol[x][y][l]=(kol[x][y][l]+kol[x+1][y][l])%inf;
            if (i[x][y]==i[x+dx-1][y+dy+1]) kol[x][y][l+1]=(kol[x][y][l+1]+kol[x+1][y][l])%inf;
        }
        dx--;
        dy++;
    }
    kol[x][y].push_back(0);
    k=kol[x][y+1].size();
    dx=k;
    dy=1;
    for (;l<k;l++) kol[x][y].push_back(0);
    for (l=0;l<k;l++){
        if (kol[x][y+1][l]!=0) {
            if (i[x][y]==i[x+dx][y+dy]) kol[x][y][l+1]=(kol[x][y][l+1]+kol[x][y+1][l])%inf;
            if (i[x][y]==i[x+dx-1][y+dy+1]) kol[x][y][l+2]=(kol[x][y][l+2]+kol[x][y+1][l])%inf;
        }
        dx--;
        dy++;
    }

}

void queue_search(){
    while (!v.empty()){
        re_count(v.front().first,v.front().second);
        v.pop();
    }
}

int main()
{
    int n,m,l,r;
    char t;
    cin>>n>>m;
    for (l=0;l<n;l++)
        for (r=0;r<m;r++){
            cin>>t;
            i[l][r]=t;
        }
    for (r=0;r<=m;r++)
        i[n][r]='%';
    for (l=0;l<=n;l++)
        i[l][m]='%';
    _begin(n,m);
    queue_search();
    cout<<kol[0][0][m-1];
    //cout<<kol[0][0];
//    for (l=0;l<n;l++){
//        for (r=0;r<m;r++){
//            cout<<kol[l][r]<<' ';}cout<<endl;}
    return 0;
}