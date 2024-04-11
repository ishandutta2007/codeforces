#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int ma[2002][2002];

queue<pair<int, int> > c;

int n,m;

void check(int y, int x){
    int v=0;
    if (y==0) v++;
    else if (ma[y-1][x]==1) v++;
    if (x==0) v++;
    else if(ma[y][x-1]==1) v++;
    if (y==n-1) v++;
    else if (ma[y+1][x]==1) v++;
    if (x==m-1) v++;
    else if(ma[y][x+1]==1) v++;
    if (v>=3) c.push({y, x});
}

void cy(int y, int x){
    for (int i=y-3;i<=y+3;i++){
        for (int ii=x-3;ii<=x+3;ii++){
            if (i>=0&&ii>=0&&i<n&&ii<m) check(i, ii);
        }
    }
}

string ss[2002];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int f=0;
    for (int i=0;i<n;i++){
        cin>>ss[i];
        for (int ii=0;ii<m;ii++){
            if (ss[i][ii]!='.'){
                ma[i][ii]=1;
            }
            else{
                f++;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            check(i, ii);
        }
    }
    while (!c.empty()){
        auto x=c.front();
        c.pop();
        //cout<<x.F<<" "<<x.S<<endl;
        if (ma[x.F][x.S]==0){
            if (x.F+1<n&&ma[x.F+1][x.S]==0){
                ma[x.F+1][x.S]=1;
                ma[x.F][x.S]=1;
                f-=2;
                cy(x.F, x.S);
                ss[x.F][x.S]='^';
                ss[x.F+1][x.S]='v';
            }
            if (x.F-1>=0&&ma[x.F-1][x.S]==0){
                ma[x.F-1][x.S]=1;
                ma[x.F][x.S]=1;
                f-=2;
                cy(x.F, x.S);
                ss[x.F][x.S]='v';
                ss[x.F-1][x.S]='^';
            }
            if (x.S+1<m&&ma[x.F][x.S+1]==0){
                ma[x.F][x.S+1]=1;
                ma[x.F][x.S]=1;
                f-=2;
                cy(x.F, x.S);
                ss[x.F][x.S]='<';
                ss[x.F][x.S+1]='>';
            }
            if (x.S-1>=0&&ma[x.F][x.S-1]==0){
                ma[x.F][x.S-1]=1;
                ma[x.F][x.S]=1;
                f-=2;
                cy(x.F, x.S);
                ss[x.F][x.S]='>';
                ss[x.F][x.S-1]='<';
            }

        }
    }
    if (f>0){
        cout<<"Not unique"<<endl;
    }
    else{
        for (int i=0;i<n;i++){
            cout<<ss[i]<<'\n';
        }
    }
}