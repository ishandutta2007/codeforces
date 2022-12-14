#include<bits/stdc++.h>
using namespace std;
string a,b,c;
int dp[1111][55][55],n,m,k,ni,nj,nh,rp,ans;
struct KMP
{
        int fail[222];
        string s;
        int next(int j,char c)
        {
                for (;j!=-1 && s[j]!=c;j=fail[j]);
                return j+1;
        }
        void Init()
        {
                fail[0]=-1;
                int f=0;
                for (int i=1;i<s.size();i++)
                {
                        fail[i]=f;
                        f=next(f,s[i]);
                }
        }
}u,v;
int main()
{
        cin>>a>>b>>c;
        b+='$';c+='$';
        u.s=b;v.s=c;
        u.Init();v.Init();
        n=a.size();m=b.size();k=c.size();
        for (int i=0;i<=n;i++)
        {
                for (int j=0;j<=m;j++)
                {
                        for (int h=0;h<=k;h++)
                        {
                                dp[i][j][h]=-1e9;
                        }
                }
        }
        dp[0][0][0]=0;
        for (int i=0;i<n;i++)
        {
                for (int j=0;j<m-1;j++)
                {
                        for (int h=0;h<k-1;h++)
                        {
                                if (dp[i][j][h]<-1e8) continue;
                                for (int p=0;p<26;p++)
                                {
                                        if (a[i]!='*' && a[i]!=p+'a') continue;
                                        ni=i+1;nj=u.next(j,p+'a');nh=v.next(h,p+'a');
                                        rp=dp[i][j][h];
                                        if (nj==m-1) 
                                        {
                                                rp++;
                                                nj=u.fail[nj];
                                        }
                                        if (nh==k-1)
                                        {
                                                rp--;
                                                nh=v.fail[nh];
                                        }
                                        dp[ni][nj][nh]=max(dp[ni][nj][nh],rp);
                                }
                        }
                }
        }
        ans=-1e9;
        for (int i=0;i<m-1;i++)
        {
                for (int j=0;j<k-1;j++)
                {
                        ans=max(ans,dp[n][i][j]);
                }
        }
        printf("%d\n",ans);
        return 0;
}