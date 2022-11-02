/*iie senpai, WATASHITACHI NO PROBLEM DESU!!!*/
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int t;
 
int plusi(int a,int b)
{
    long long cur = 0LL+a+b;
    if(cur < 0)
        cur+=MOD;
    cur%=MOD;
    return (int) cur;
}
 
int multi(int a,int b)
{
    long long cur =1LL*a*b;
    cur%=MOD;
    return (int) cur;
}
 
int power(int base,int pow)
{
    if(pow==0)
        return 1;
    else
    {
        int get = power(base,pow/2);
        long long cur = 1LL * multi(get,get);
        if(pow%2==1)
            cur*=base;
        cur%=MOD;
        return (int) cur;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin>>t;
    while(t--)
    {
        int n,p,i;
        cin>>n>>p;
        int val[n];
        for(i=0;i<n;i++)
            cin>>val[i];
        sort(val,val+n, greater<int>());
        int maxi = val[0];
        int bit[4*n+10][2];
        for(i=0;i<2*n+10;i++)
        {
            bit[i][0] = 0;
            bit[i][1] = 0;
        }
        int sum_left=0,sum_right=0;
        int issue_digit = 0;
        bool left = false;
        priority_queue<int> pq;
        map<int,int> mp;
        if(p!=1){
        int here=1,real,counti=2;
        for(i=n-2;i>=0;i--)
        {
            if(val[i+1]==val[i])
                counti+=2;
            else
            {
                real = val[i+1];
                while(counti)
                {
                    if(real<val[i])
                    {
                        if(!mp.count(real))
                            mp.insert({real,here});
                        here++;
                        counti/=2;
                        real++;
                    }
                    else
                        break;
                }
                counti+=2;
                real = val[i];
            }
        }
        real = val[0];
        while(counti)
        {
            if(!mp.count(real))
                mp.insert({real,here});
            here++;
            counti/=2;
            real++;
        }
        for(i=0;i<n;i++)
        {
            if(left)
            {
                int cur = mp[val[i]];
                bit[cur][1]++;
                while(bit[cur][1]==p)
                {
                    bit[cur][1]=0;
                    if(bit[cur][0]==p-1)
                        pq.push(cur);
                    cur++;
                    bit[cur][1]++;
                }
                if(bit[cur][0]==bit[cur][1]-1)
                    pq.push(cur);
                while(!pq.empty())
                {
                    issue_digit = pq.top();
                    if(bit[cur][0]!=bit[cur][1])
                        break;
                    else
                        pq.pop();
                }
                if(pq.empty())
                {
                    issue_digit = 0;
                    left = false;
                }
                else if (bit[issue_digit][0] > bit[issue_digit][1])
                {
                    left = true;
                }
                else
                {
                    left = false;
                }
                sum_right=plusi(sum_right,power(p,val[i]));
            }
            else
            {
                int cur = mp[val[i]];
                bit[cur][0]++;
                while(bit[cur][0]==p)
                {
                    bit[cur][0]=0;
                    if(bit[cur][1]==p-1)
                        pq.push(cur);
                    cur++;
                    bit[cur][0]++;
                }
                if(bit[cur][1]==bit[cur][0]-1)
                    pq.push(cur);
                while(!pq.empty())
                {
                    issue_digit = pq.top();
                    if(bit[cur][0]!=bit[cur][1])
                        break;
                    else
                        pq.pop();
                }
                if(pq.empty())
                {
                    issue_digit = 0;
                    left = false;
                }
                else if (bit[issue_digit][0] > bit[issue_digit][1])
                {
                    left = true;
                }
                else
                {
                    left = false;
                }
                sum_left=plusi(sum_left,power(p,val[i]));
            }
        }
        cout<<plusi(sum_left,-sum_right)<<"\n";
        }
        else
        {
            if(n%2==0)
                cout<<0<<"\n";
            else
                cout<<1<<"\n";
        }
    }
    return 0;
}