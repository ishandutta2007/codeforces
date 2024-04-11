#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;
map<int,int> values;
vector< pair<int/*number*/,int/*numbers in number*/> >all,help;
void make_value(int x)
{
    if(values.count(x))return;
    values[x]=x;
}
long long merge_sort(int l,int r)
{
    if(l==r)return 0;
    int av=(l+r)/2;
    long long ans=merge_sort(l,av)+merge_sort(av+1,r);
    int l_pos=l,r_pos=av+1,sum=0,p=0;
    while(l_pos<=av&&r_pos<=r)
    {
        if(all[l_pos].first<all[r_pos].first)
        {
        ans=ans+1LL*sum*all[l_pos].second;
        help[p]=all[l_pos];
        l_pos++;
        p++;
        }
        else
        {
        sum=sum+all[r_pos].second;
        help[p]=all[r_pos];
        r_pos++;
        p++;
        }
    }

    while(l_pos<=av)
    {
        ans=ans+1LL*sum*all[l_pos].second;
        help[p]=all[l_pos];
        l_pos++;
        p++;
    }

    while(r_pos<=r)
    {
        sum=sum+all[r_pos].second;
        help[p]=all[r_pos];
        r_pos++;
        p++;
    }

    for(int j=0;j<p;j++)all[l+j]=help[j];
    /*
    cout<<l<<" "<<r<<" "<<ans<<endl;
    for(int j=l;j<=r;j++)cout<<all[j].first<<" "<<all[j].second<<endl;
    cout<<"---"<<endl;
    */
    return ans;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();


cin>>n;
int a,b;
for(int i=1;i<=n;i++)
{
    cin>>a>>b;
    make_value(a);
    make_value(b);
    swap(values[a],values[b]);
}

int prev=0;
for(auto k:values)
{
    //cout<<"k "<<k.first<<" "<<k.second<<endl;
    if(k.first-prev>=2)
    {
        all.push_back({prev+1,k.first-prev-1});
    }
    prev=k.first;
    all.push_back({k.second,1});
}
help=all;
//cout<<"all: "<<endl;for(auto k:all)cout<<k.first<<" "<<k.second<<endl;
cout<<merge_sort(0,all.size()-1)<<endl;
return 0;
}