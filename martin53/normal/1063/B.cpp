#include<bits/stdc++.h>
using namespace std;
const int nmax=2e3+42;
int n,m;
int r,c;
int x,y;
char inp[nmax][nmax];

vector< pair<int,int> > seen[nmax][nmax];

struct state
{
int x,y,moves_left,moves_right;
};


deque< state > q;

state make_state(int x_,int y_,int m1_,int m2_)
{
    state now;
    now.x=x_;
    now.y=y_;
    now.moves_left=m1_;
    now.moves_right=m2_;
    return now;
}
bool good(int x,int y)
{
    if(1<=x&&x<=n&&1<=y&&y<=m&&inp[x][y]=='.')return 1;
    return 0;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n>>m;
cin>>r>>c;
cin>>x>>y;
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    cin>>inp[i][j];

q.push_back(make_state(r,c,0,0));
int ans=0;
state now;
while(q.size())
{
    now=q.front();
    q.pop_front();
    bool bad=0;
    for(auto k:seen[now.x][now.y])
        if(k.first<=now.moves_left&&k.second<=now.moves_right){bad=1;break;}
    if(bad)continue;
    seen[now.x][now.y].push_back({now.moves_left,now.moves_right});

    if(good(now.x+1,now.y))q.push_front(make_state(now.x+1,now.y,now.moves_left,now.moves_right));
    if(good(now.x-1,now.y))q.push_front(make_state(now.x-1,now.y,now.moves_left,now.moves_right));

    if(now.moves_right!=y&&good(now.x,now.y+1))q.push_back(make_state(now.x,now.y+1,now.moves_left,now.moves_right+1));
    if(now.moves_left!=x&&good(now.x,now.y-1))q.push_back(make_state(now.x,now.y-1,now.moves_left+1,now.moves_right));
}
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    ans=ans+(seen[i][j].size()>0);
cout<<ans<<endl;
return 0;
}