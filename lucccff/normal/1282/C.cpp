#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,a,b,x,y;
    long long c[200010],d[200010];
    pair <long long,pair<long long,long long>> p[200010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>m>>a>>b;
        x=0;
        for(j=0;j<n;j++) {
            cin>>c[j];
            x+=c[j];
        }
        x=n-x;
        for(j=0;j<n;j++) {
            cin>>d[j];
            p[j]=make_pair(d[j],make_pair(a+c[j]*(b-a),c[j]));
        }
        p[n]=make_pair(m+1,make_pair(0,0));
        sort(p,p+n);
        for(j=1;j<n;j++) {
            p[j].second.first+=p[j-1].second.first;
            p[j].second.second+=p[j-1].second.second;
        }
        if ((p[0].first-1)/a>x) {
            if (p[0].first-1>a*x+b*(n-x)) {
                y=n;
            }
            else {
                y=x+(p[0].first-1-a*x)/b;
            }
        }
        else {
            y=(p[0].first-1)/a;
        }
        if (y<0) y=0;
        for(j=1;j<=n;j++) {
            if (p[j].first-1>m) {
                if (m>=p[j-1].second.first) {
                    k=m-p[j-1].second.second*b;
                    l=p[j-1].second.second;
                    if (k/a>x) {
                        if (k>a*x+b*(n-x-l)) {
                            l=n;
                        }
                        else {
                            l+=x+(k-x*a)/b;
                        }
                    }
                    else {
                        l+=k/a;
                    }
                    if (l>y) y=l;
                }
                break;
            }
            if (p[j].first-1>=p[j-1].second.first) {
                k=p[j].first-1-p[j-1].second.second*b;
                l=p[j-1].second.second;
                if (k/a>x) {
                    if (k>a*x+b*(n-x-l)) {
                        l=n;
                    }
                    else {
                        l+=x+(k-x*a)/b;
                    }
                }
                else {
                    l+=k/a;
                }
                if (l>y) y=l;
            }
        }
        cout<<y<<endl;
    }
    return 0;
}