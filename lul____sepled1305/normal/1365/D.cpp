/**"I guarantee that this corpse is Ushiromiya Kinzo's corpse...!!"**/
#include<bits/stdc++.h>
using namespace std;
int T;
string s[50];
bool visit[50][50];
int n,m,i,j;

void flood(int x,int y)
{
    if(!visit[x][y] && s[x].at(y)!='#')
    {
        visit[x][y]=true;
        if(s[x].at(y)=='B')
        {
            if(x!=0 && s[x-1].at(y)=='.')
                s[x-1].at(y)='#';
            if(y!=0 && s[x].at(y-1)=='.')
                s[x].at(y-1)='#';
            if(x!=n-1 && s[x+1].at(y)=='.')
                s[x+1].at(y)='#';
            if(y!=m-1 && s[x].at(y+1)=='.')
                s[x].at(y+1)='#';
        }
        else
        {
            if(x!=0)
                flood(x-1,y);
            if(y!=0)
                flood(x,y-1);
            if(x!=n-1)
                flood(x+1,y);
            if(y!=m-1)
                flood(x,y+1);
        }
    }
}

int main()
{
    cin>>T;
    while(T--)
    {
        bool bad=false,good = false;
        cin>>n>>m;
        for(i=0; i<50; i++)
            for(j=0; j<50; j++)
                visit[i][j] = false;
        for(i=0; i<n; i++)
            cin>>s[i];
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(s[i].at(j)=='G')
                    good = true;
                if(s[i].at(j)=='B')
                    bad = true;
            }
        }
        if(s[n-1].at(j-1)=='B')
            cout<<"No\n";
        else if (!good)
            cout<<"Yes\n";
        else
        {
            flood(n-1,m-1);
            for(i=0; i<50; i++)
                for(j=0; j<50; j++)
                    visit[i][j] = false;
            flood(n-1,m-1);
            bool pass = true;
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    if(s[i].at(j)=='G' && !visit[i][j])
                        pass = false;
                    if(s[i].at(j)=='B' && visit[i][j])
                        pass = false;
                }
            }
            if(pass)
                cout<<"Yes\n";
            else
                cout<<"No\n";

        }
    }
    return 0;
}