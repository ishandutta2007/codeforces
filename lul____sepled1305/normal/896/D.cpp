/**If I pass this in one try, I will drop ciconia and start reading Ao no Kanata no Four Rhythm.**/
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 1e5+10;
int n,p,l,r,i,j,ans,c,ori_p;
vector<pii> divisor;
vector<pii> pre_cal[20];

int plusi(int a, int b, int mod)
{
    long long cur = (0LL+a+b)%mod;
    if(cur<0) cur+=mod;
    return (int) cur;
}

int multi(int a,int b,int mod)
{
    long long cur = 1LL*a*b;
    cur%=mod;
    return (int) cur;
}

int power(int base, int pow,int mod)
{
    if(pow==0)
        return 1;
    if(pow==1)
        return base%mod;

    int cur = power(base, pow/2,mod);
    cur = multi(cur,cur,mod);
    if(pow%2)
        cur = multi(cur,base,mod);
    return cur;
}

int inverse(int base, int base_p, int p)
{
    int totient  = p - p/base_p;
    return power(base, totient - 1, p);
}

int main()
{
    cin>>n>>p>>l>>r;
    ori_p = p;
    for(i=2;i<=sqrt(ori_p);i++)
    {
        int mul = 1;
        while(p%i==0)
        {
            p/=i;
            mul*=i;
        }
        if(mul>1)
            divisor.push_back({i,mul});
    }
    if(p>1)
        divisor.push_back({p,p});
    for(j=0;j<divisor.size();j++)
    {
        pre_cal[j].push_back({1,0});
        for(i=1;i<N;i++)
        {
            int cur = i;
            int counti = 0;
            while(cur%divisor[j].first==0)
            {
                counti++;
                cur/=divisor[j].first;
            }
            long long ori = 1LL * cur * pre_cal[j][i-1].first;
            ori%=divisor[j].second;
            cur = (int) ori;
            pre_cal[j].push_back({cur,counti+pre_cal[j][i-1].second});
        }
    }
    for(c=0;c<=(n-l);c++)
    {
        int maxa = min((n+r-c)/2,n-c);
        int mina = (n+l-c+1)/2;
        int ans_here = 0;
        vector<int> remainder;
        if(mina < l)
            mina = l;
        if(maxa < mina)
            continue;
        maxa++;
        for(i=0;i<divisor.size();i++)
        {
            int powe, remain1;
            if(maxa > n)
                remain1 = 0;
            else
            {
                powe = pre_cal[i][n].second - pre_cal[i][c].second - pre_cal[i][maxa].second - pre_cal[i][n-c-maxa].second;
                remain1 = multi(pre_cal[i][n].first, inverse(pre_cal[i][c].first,divisor[i].first,divisor[i].second),divisor[i].second);
                remain1 = multi(remain1, inverse(pre_cal[i][maxa].first,divisor[i].first,divisor[i].second),divisor[i].second);
                remain1 = multi(remain1, inverse(pre_cal[i][n-c-maxa].first,divisor[i].first,divisor[i].second),divisor[i].second);
                remain1 = multi(remain1, power(divisor[i].first,powe,divisor[i].second),divisor[i].second);
            }

            powe = pre_cal[i][n].second - pre_cal[i][c].second - pre_cal[i][mina].second - pre_cal[i][n-c-mina].second;
            int remain2 = multi(pre_cal[i][n].first, inverse(pre_cal[i][c].first,divisor[i].first,divisor[i].second),divisor[i].second);
            remain2 = multi(remain2, inverse(pre_cal[i][mina].first,divisor[i].first,divisor[i].second),divisor[i].second);
            remain2 = multi(remain2, inverse(pre_cal[i][n-c-mina].first,divisor[i].first,divisor[i].second),divisor[i].second);
            remain2 = multi(remain2, power(divisor[i].first,powe,divisor[i].second),divisor[i].second);

            int here = plusi(-remain1,remain2,divisor[i].second);
            remainder.push_back(here);
        }
        int st = 0;
        int cur = 1;
        for(i=0;i<divisor.size();i++)
        {
            int inv = inverse(cur,divisor[i].first,divisor[i].second);
            int here = plusi(remainder[i],-st,divisor[i].second);
            int ori = cur;
            cur*=divisor[i].second;
            int newi = multi(here,inv,cur);
            newi = multi(newi,ori,cur);
            st = plusi(st,newi,cur);
        }
        ans= plusi(ans,st,ori_p);
    }
    cout<<ans;
}