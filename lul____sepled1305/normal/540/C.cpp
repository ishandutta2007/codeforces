
#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a,b,x,y,nodex,nodey;
using pii = pair<int,int>;
 
int main()
{
    cin>>n>>m;
    bool visit[n][m];
    bool con1 = false, con2=false, con3=true, con4=false;
    int counti=0;
    string s[n];
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
        visit[i][j] = false;
    for(i=0;i<n;i++)
        cin>>s[i];
    cin>>a>>b;
    a--; b--;
    cin>>x>>y;
    x--; y--;
    visit[a][b] = true;
    queue<pii> qu;
    qu.push({a,b});
    while(!qu.empty())
    {
        pii node = qu.front();
        qu.pop();
        int k = node.first, l = node.second;
        
        if(k!=0 && s[k-1].at(l)=='.' && visit[k-1][l]==false)
            visit[k-1][l] = true, qu.push({k-1,l});
        if(k!=n-1 && s[k+1].at(l)=='.' && visit[k+1][l]==false)
            visit[k+1][l] = true, qu.push({k+1,l});
        if(l!=0 && s[k].at(l-1)=='.' && visit[k][l-1]==false)
            visit[k][l-1] = true, qu.push({k,l-1});
        if(l!=m-1 && s[k].at(l+1)=='.' && visit[k][l+1]==false)
            visit[k][l+1] = true, qu.push({k,l+1});
    }
        
    if(x!=0 && visit[x-1][y])
        con4=true,counti++;
    if(x!=n-1 && visit[x+1][y])
        con4=true,counti++;
    if(y!=0 && visit[x][y-1])
        con4=true,counti++;
    if(y!=m-1 && visit[x][y+1])
        con4=true,counti++;
    
    if(visit[x][y] || (s[x].at(y)=='X' && con4))
        con2 = true;
    
    if(counti>=2 || s[x].at(y)=='X')
        con1 = true;
        
    if(a==x && b==y && counti==0)
        con3 = false;
    if(con1 && con2 && con3)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}