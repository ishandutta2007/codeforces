#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<utility>
#include<iterator>
#include<string>
#include<vector>
using namespace std;
const int INF=2000000000;
const int MAXN=100010;
int n,a[MAXN],b[MAXN],c[MAXN],K,ans=-INF;
map<pair<int,int>,int> M1,M2;
pair<pair<int,int>,int> P1,P2;
void DFS1(int x,int A,int B,int C)
{
    if(x==K+1)
    {
        if(!M1.count(make_pair(B-A,C-A))) M1[make_pair(B-A,C-A)]=A;
        else M1[make_pair(B-A,C-A)]=max(M1[make_pair(B-A,C-A)],A);
        return;
    }
    DFS1(x+1,A+a[x],B+b[x],C);
    DFS1(x+1,A+a[x],B,C+c[x]);
    DFS1(x+1,A,B+b[x],C+c[x]);
}
void DFS2(int x,int A,int B,int C)
{
    if(x==n+1)
    {
        pair<int,int> tmp=make_pair(A-B,A-C);
        if(M1.count(tmp)&&A+M1[tmp]>ans)
        {
            ans=A+M1[tmp];
            P1=(*M1.find(tmp));
            P2=make_pair(make_pair(B-A,C-A),A);
        }
        return;
    }
    DFS2(x+1,A+a[x],B+b[x],C);
    DFS2(x+1,A+a[x],B,C+c[x]);
    DFS2(x+1,A,B+b[x],C+c[x]);
}
vector<string> vec1,vec2,ans1,ans2;
void print(const vector<string> &vec)
{
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<endl;
}
void dfs1(int x,int A,int B,int C)
{
    if(x==K+1)
    {
        if(B-A==P1.first.first&&C-A==P1.first.second&&A==P1.second) ans1=vec1;
        return;
    }
    vec1.push_back("LM");
    dfs1(x+1,A+a[x],B+b[x],C);
    vec1.pop_back();
    vec1.push_back("LW");
    dfs1(x+1,A+a[x],B,C+c[x]);
    vec1.pop_back();
    vec1.push_back("MW");
    dfs1(x+1,A,B+b[x],C+c[x]);
    vec1.pop_back();
}
void dfs2(int x,int A,int B,int C)
{
    if(x==n+1)
    {
        if(B-A==P2.first.first&&C-A==P2.first.second&&A==P2.second) ans2=vec2;
        return;
    }
    vec2.push_back("LM");
    dfs2(x+1,A+a[x],B+b[x],C);
    vec2.pop_back();
    vec2.push_back("LW");
    dfs2(x+1,A+a[x],B,C+c[x]);
    vec2.pop_back();
    vec2.push_back("MW");
    dfs2(x+1,A,B+b[x],C+c[x]);
    vec2.pop_back();
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
    K=n/2;
    DFS1(1,0,0,0);
    DFS2(K+1,0,0,0);
    if(ans==-INF) {puts("Impossible");return 0;}
    dfs1(1,0,0,0);
    dfs2(K+1,0,0,0);
    print(ans1);
    print(ans2);
    return 0;
}