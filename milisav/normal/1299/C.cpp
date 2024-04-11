#include<bits/stdc++.h>
#define maxn 2000000
using namespace std;
vector<pair<long long,long long> > q;
int n;
int a[maxn];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++) {
        q.push_back({a[i],1});
        int l=q.size();
        while(q.size()>=2 && (q[l-1].first+q[l-2].first)*q[l-2].second<q[l-2].first*(q[l-1].second+q[l-2].second)) {
            pair<long long,long long> p1=q[l-1];
            pair<long long,long long> p2=q[l-2];
            q.pop_back();
            q.pop_back();
            q.push_back({p1.first+p2.first,p1.second+p2.second});
            l--;
        }
    }
    for(auto t:q) {
        long double p1=t.first;
        long double q1=t.second;
        long double ans=p1/q1;
        for(int i=0;i<t.second;i++) printf("%.10Lf\n",ans);
    }
    return 0;
}