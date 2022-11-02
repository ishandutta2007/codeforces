/** Mion Best Girl **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int MOD = 1e9+7;
const int chtholly = 0;
int T;

void travel (vector<pii> &divisor, vector<int> &print, int save, int mul, bool fir)
{
    if(divisor.size() == 1)
    {
        int cur = mul;
        for(int i=0;i<=divisor.back().second;i++)
        {
            if(cur != save && cur!= 1)
                print.push_back(cur);
            cur*=divisor.back().first;
        }
        return;
    }

    int cur = mul,i;
    pii safe = divisor.back();
    divisor.pop_back();
    if(!fir)
        travel(divisor,print,save,mul,false);
    for(i=0;i<safe.second;i++)
    {
        cur*=safe.first;
        travel(divisor,print,save,cur,false);
    }
    if(fir)
        travel(divisor,print,save,mul,true);
    divisor.push_back(safe);
}

int GCD(int a, int b)
{

    if(a>b)
        swap(a,b);

    if(a == 1)
        return 1;
    if(b%a == 0)
        return a;
    else
        return GCD(b%a,a);
}

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/
    cin>>T;
    while(T--)
    {
        int n,i,counti=0;
        vector<pii> divisor;
        cin>>n;
        const int N = n;
        for(i=2;i*i <= N;i++)
        {
            if(n%i == 0)
            {
                divisor.push_back({i,0});
                while(n%i == 0)
                {
                    divisor[counti].second++;
                    n/=i;
                }
                counti++;
            }
        }
        if(n!=1)
            divisor.push_back({n,1});

        if(divisor.size() == 1)
        {
            int num = 1;
            for(i=0;i<divisor[0].second;i++)
            {
                num*=divisor[0].first;
                cout<<num<<' ';
            }
            cout<<endl;
            cout<<0<<endl;
        }
        else
        {
            vector<int> print;
            n = N;
            int siz = divisor.size();
            int save  = divisor[siz-1].first * divisor[0].first;
            travel(divisor,print,save,1,true);
            print.push_back(save);
            for(i=0;i<print.size();i++)
                cout<<print[i]<<' ';
            cout<<endl;
            if(GCD(print[1],print[0])==1)
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
    }
    return chtholly;
}