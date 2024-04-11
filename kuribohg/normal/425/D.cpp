#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<unordered_set>
#include<utility>
#include<cmath>
#define x first
#define y second
#define used used2
using namespace std;
typedef long long LL;
const int MAXN=100010;
pair<int,int> P[MAXN];
unordered_set<LL> S;
inline LL Hash(const pair<int,int> &p)
{
	return (LL)p.first*100001+p.second;
}
int n,L,R,K,ans,tot;
bool used[MAXN];
int main()
{
    scanf("%d",&n);
    K=(int)sqrt(n);
    for(int i=1;i<=n;i++) scanf("%d%d",&P[i].x,&P[i].y);
    sort(P+1,P+n+1);
    L=1;
    for(int i=1;i<=n;i++) S.insert(Hash(P[i]));
    while(L<=n)
    {
        R=L;
        while(R+1<=n&&P[R+1].x==P[L].x) R++;
        if(R-L+1>K) {L=R+1;continue;}
        for(int i=L;i<=R;i++)
            for(int j=i+1;j<=R;j++)
            {
                pair<int,int> tar1,tar2;
                tar1=make_pair(P[i].x+P[j].y-P[i].y,P[i].y);
                tar2=make_pair(P[i].x+P[j].y-P[i].y,P[j].y);
                if(S.count(Hash(tar1))&&S.count(Hash(tar2))) ans++;
                tar1=make_pair(P[i].x-P[j].y+P[i].y,P[i].y);
                tar2=make_pair(P[i].x-P[j].y+P[i].y,P[j].y);
                if(S.count(Hash(tar1))&&S.count(Hash(tar2))) ans++;
            }
        for(int i=L;i<=R;i++) used[i]=true,S.erase(Hash(P[i]));
        L=R+1;
    }
    S.clear();
    for(int i=1;i<=n;i++)
        if(!used[i]) P[++tot]=P[i],swap(P[tot].x,P[tot].y);
    n=tot;
    sort(P+1,P+n+1);
    L=1;
    for(int i=1;i<=n;i++) S.insert(Hash(P[i]));
    while(L<=n)
    {
        R=L;
        while(R+1<=n&&P[R+1].x==P[L].x) R++;
        for(int i=L;i<=R;i++)
            for(int j=i+1;j<=R;j++)
            {
                pair<int,int> tar1,tar2;
                tar1=make_pair(P[i].x+P[j].y-P[i].y,P[i].y);
                tar2=make_pair(P[i].x+P[j].y-P[i].y,P[j].y);
                if(S.count(Hash(tar1))&&S.count(Hash(tar2))) ans++;
                tar1=make_pair(P[i].x-P[j].y+P[i].y,P[i].y);
                tar2=make_pair(P[i].x-P[j].y+P[i].y,P[j].y);
                if(S.count(Hash(tar1))&&S.count(Hash(tar2))) ans++;
            }
        for(int i=L;i<=R;i++) S.erase(Hash(P[i]));
        L=R+1;
    }
    printf("%d\n",ans);
    return 0;
}