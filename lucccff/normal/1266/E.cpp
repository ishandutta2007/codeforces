#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

map <pair<int,int>,int> p;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,s=0,q,x=0,y,z=0;
    long long a[200010],b[200010];
    cin>>n;
    for(i=1;i<=n;i++) {
        cin>>a[i];
        s+=a[i];
        b[i]=0;
    }
    cin>>q;
    for(i=0;i<q;i++) {
        cin>>k>>l>>m;
        if (p.count(make_pair(k,l))) {
            z--;
            y=p[make_pair(k,l)];
            if (b[y]-->a[y]) x--;
        }
        if (m!=0) {
            z++;
            p[make_pair(k,l)]=m;
            b[m]++;
            if (b[m]>a[m]) x++;
        }
        else if (p.count(make_pair(k,l))){
            p.erase(make_pair(k,l));
        }
        cout<<s-z+x<<endl;
    }
    return 0;
}