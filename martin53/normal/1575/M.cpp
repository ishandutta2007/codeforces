#include<bits/stdc++.h>
using namespace std;

const int nmax=2e3+42;

int n,m;
int inp[nmax][nmax];

int up[nmax];

int mem_score[nmax][nmax];

int score[nmax][nmax];

vector< pair<int/*a*/,int/*b*/> > lines;//ax+b

pair<int,int> meet(pair<int,int> line_1,pair<int,int> line_2)
{
    return {line_1.second-line_2.second,line_2.first-line_1.first};
}
void add_line(pair<int/*a*/,int/*b*/> cur)
{
    //while(lines.size()&&lines.back().second<=cur.second)lines.pop_back();
    if(lines.size()&&lines.back().second<=cur.second)return;

    while(lines.size()>=2)
    {
        pair<int,int> s=meet(lines[lines.size()-2],lines[lines.size()-1]);

        pair<int,int> t=meet(lines[lines.size()-1],cur);

        if(1LL*s.first*t.second<=1LL*s.second*t.first)lines.pop_back();
        else break;
    }

    lines.push_back(cur);
}

int pointer=0;

int exact(pair<int,int> l,int x)
{
    return x*l.first+l.second;
}

int eval(int x)
{
    while(pointer-1>=0&&exact(lines[pointer],x)>exact(lines[pointer-1],x))pointer--;

    //cout<<x<<" -> "<<pointer<<" : "<<exact(lines[pointer],x)<<endl;

    return exact(lines[pointer],x);
}

void solve()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)score[i][j]=1e9;

    for(int j=1;j<=m;j++)up[j]=-4e3;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(inp[i][j])up[j]=i;

        lines={};

        for(int y1=m;y1>=1;y1--)
        {
            pair<int,int> cur={-2*y1,(up[y1]-i)*(up[y1]-i)+y1*y1};

            add_line(cur);
        }

        //cout<<"i= "<<i<<" : ";for(auto w:lines)cout<<w.first<<" "<<w.second<<"\t";cout<<endl;

        pointer=lines.size()-1;

        for(int y2=1;y2<=m;y2++)
           score[i][y2]=eval(y2)+y2*y2;
    }

}

void flip()
{
    for(int i=1;i<=n+1-i;i++)
        for(int j=1;j<=m;j++)
            swap(inp[i][j],inp[n+1-i][j]);
}

int main()
{
    scanf("%i%i",&n,&m);
    n++;
    m++;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char c=getchar();
            while(c!='0'&&c!='1')c=getchar();

            if(c=='1')inp[i][j]=1;
        }

    solve();

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)mem_score[i][j]=score[i][j];

    flip();

    solve();

    long long outp=0;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            outp+=min(mem_score[i][j],score[n+1-i][j]);

    printf("%lld\n",outp);

    return 0;
}