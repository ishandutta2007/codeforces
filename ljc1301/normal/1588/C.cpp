#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300005;
int n;
ll a,tag;
map<ll,int> cnt;
int main()
{
    int T,i;
    ll ans;
    map<ll,int>::iterator it,temp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cnt.clear(),tag=0;
        ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a);
            if(i&1)
            {
                if(!cnt.count(-tag)) cnt[-tag]=1;
                else cnt[-tag]+=1;
                tag+=a;
                for(it=cnt.begin();it!=cnt.end() && it->first+tag<0;it=temp)
                    temp=it,++temp,cnt.erase(it);
                if(cnt.count(-tag)) ans+=cnt[-tag];
            }
            else
            {
                if(!cnt.count(-tag)) cnt[-tag]=1;
                else cnt[-tag]+=1;
                tag-=a;
                for(it=cnt.end(),--it;;it=temp)
                {
                    temp=it;
                    if(it->first+tag>0)
                    {
                        if(it==cnt.begin())
                        {
                            cnt.erase(cnt.begin());
                            break;
                        }
                        else
                        {
                            --temp;
                            cnt.erase(it);
                        }
                    }
                    else break;
                }
                if(cnt.count(-tag)) ans+=cnt[-tag];
            }
            // printf("%lld\n",ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}