#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
priority_queue<int> buy,sell;
vector<int> now;
vector<int> reduce(vector<int> my)
{
    vector<int> ret={};
    for(auto k:my)
    {
        if(buy.size()&&buy.top()>k)buy.push(k);
        else if(sell.size()&&-sell.top()<k)sell.push(-k);
        else ret.push_back(k);
    }
    return ret;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
int n;
cin>>n;
long long ans=1;
string type;
int number;
for(int i=1;i<=n;i++)
{
    cin>>type>>number;
    if(type=="ADD")now.push_back(number);
    else
    {
        if(buy.size()==0&&sell.size()==0&&now.size()==0)
        {
            cout<<0<<endl;
            return 0;
        }
        if(buy.size()&&buy.top()>number)
        {
            cout<<0<<endl;
            return 0;
        }
        if(sell.size()&&-sell.top()<number)
        {
            cout<<0<<endl;
            return 0;
        }
        //sort(now.begin(),now.end());
        now=reduce(now);
        bool there=0;
        if(buy.size()&&buy.top()==number)
        {
            there=1;
            buy.pop();
            for(auto k:now)
                sell.push(-k);
        }
        else if(sell.size()&&-sell.top()==number)
        {
            there=1;
            sell.pop();
            for(auto k:now)
                buy.push(k);
        }
        else
        {
            for(auto k:now)
            {
            if(k==number)there=1,ans=ans*2%mod;
            else if(k<number)buy.push(k);
            else sell.push(-k);
            }
        }
        if(there==0)
        {
            cout<<0<<endl;
            return 0;
        }
    now={};
    }
}
now=reduce(now);
cout<<ans*(now.size()+1)%mod<<endl;
return 0;
}