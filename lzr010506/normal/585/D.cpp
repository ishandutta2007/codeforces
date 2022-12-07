#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
using namespace std;

int mid,n;
int a[30],b[30],c[30];
map<pair<int,int> ,pair<int,long long> >H;
pair<int,long long> ans;
void dfs1(int step,long long sta,int A,int B,int C)
{
    if(step == mid + 1)
    {
        pair<int,long long> temp;
        temp = H[pair<int,int>(A - B, B - C)];
        if(temp.second == 0)
            H[pair<int,int>(A - B, B - C)] = pair<int,long long>(A,sta);
        else
            H[pair<int,int>(A - B, B - C)] = max(temp,pair<int,long long>(A,sta));
        return;
    }
    dfs1(step + 1, sta << 2 | 1, A, B + b[step], C + c[step]);
    dfs1(step + 1, sta << 2 | 2, A + a[step], B, C + c[step]);
    dfs1(step + 1, sta << 2 | 3, A + a[step], B + b[step],C);
}
void dfs2(int step,long long sta,int A,int B,int C)
{
    if(step == n + 1)
    {
        pair<int,long long> temp = H[pair<int,int>(B - A, C - B)];
        if(temp.second == 0)return;
        ans = max(ans,pair<int,long long>(A + temp.first, temp.second << (n - mid << 1) | sta));
        return;
    }
    dfs2(step + 1, sta << 2 | 1, A, B + b[step], C + c[step]);
    dfs2(step + 1, sta << 2 | 2, A + a[step], B, C + c[step]);
    dfs2(step + 1, sta << 2 | 3, A + a[step], B + b[step],C);
}
int main()
{
    ans.first = -99999999;
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++)
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    mid = (n + 1) / 2;
    dfs1(1,0,0,0,0);
    dfs2(mid+1,0,0,0,0);
    if(ans.first == -99999999)
		return puts("Impossible");
    vector<int> Ans;
    for(int i = 1; i <= n; i ++)
    {
        Ans.push_back(ans.second & 3);
        ans.second >>= 2;
    }
    for(int i = Ans.size()-1;i>=0;i--)
        if(Ans[i] == 3)
            printf("LM\n");
        else if(Ans[i] == 2)
            printf("LW\n");
        else
            printf("MW\n");
	return 0;
}