#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const int N=200005,inf=0x7f7f7f7f;
#define mp make_pair
typedef long long ll;
typedef pair<long long,int> pii;
int n;ll t;
tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> tr;
tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>::iterator it;
ll a[N],s[N];
int main()
{
    scanf("%d%I64d",&n,&t);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]),s[i]=s[i-1]+a[i];
    tr.insert(mp(0,0));
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        it=tr.upper_bound(mp(s[i]-t,inf));
        if(it!=tr.end()) ans+=i-tr.order_of_key(*it);
        tr.insert(mp(s[i],i));
    }
    printf("%I64d",ans);
    return 0;
}