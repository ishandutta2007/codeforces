#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    long long a[100010];
    pair <long long,int> p[100010],q[100010];
    memset(a,0,sizeof(a));
    cin>>n>>m;
    for(i=0;i<m;i++) {
        cin>>k>>l>>t;
        a[k]+=t;
        a[l]-=t;
    }
    for(i=1;i<=n;i++) {
        p[i]=make_pair(a[i],i);
    }
    sort(p+1,p+n+1);
    for(i=1;i<=n;i++) {
        q[i]=p[i];
    }
    k=1;
    l=n;
    m=0;
    while(k<l) {
        while(k<l&&q[k].first==0) k++;
        while(l>k&&q[l].first==0) l--;
        if (k==l) break;
        if (q[k].first+q[l].first>0) {
            //cout<<p[l].second<<' '<<p[k].second<<' '<<-p[k].first<<endl;
            q[l].first+=q[k].first;
            k++;
        }
        else if (q[k].first+q[l].first<0) {
            //cout<<p[l].second<<' '<<p[k].second<<' '<<p[l].first<<endl;
            q[k].first+=q[l].first;
            l--;
        }
        else {
            //cout<<p[l].second<<' '<<p[k].second<<' '<<p[l].first<<endl;
            k++;
            l--;
        }
        m++;
    }
    cout<<m<<endl;
    k=1;
    l=n;
    while(k<l) {
        while(k<l&&p[k].first==0) k++;
        while(l>k&&p[l].first==0) l--;
        if (k==l) break;
        if (p[k].first+p[l].first>0) {
            cout<<p[l].second<<' '<<p[k].second<<' '<<-p[k].first<<endl;
            p[l].first+=p[k].first;
            k++;
        }
        else if (p[k].first+p[l].first<0) {
            cout<<p[l].second<<' '<<p[k].second<<' '<<p[l].first<<endl;
            p[k].first+=p[l].first;
            l--;
        }
        else {
            cout<<p[l].second<<' '<<p[k].second<<' '<<p[l].first<<endl;
            k++;
            l--;
        }
    }
    return 0;
}