#include<bits/stdc++.h>
using namespace std;
long long n,q;
int a[200000];
pair<int,int> ans[200000];
deque<int> d;
vector<pair<int,int> > up;
int main() {
    scanf("%lld %lld",&n,&q);
    int m=0;
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        m=max(m,a[i]);
        d.push_back(a[i]);
    }
    long long r;
    long long l=0;
    while(d.front() != m) {
        int a1=d.front();
        d.pop_front();
        int b1=d.front();
        d.pop_front();
        if(a1>=b1) {
            d.push_front(a1);
            d.push_back(b1);
        }
        else {
            d.push_front(b1);
            d.push_back(a1);
        }
        ans[++l]={a1,b1};
    }
    n=0;
    while(d.size()>0) {
        a[n]=d.front();
        d.pop_front();
        n++;
    }
    for(int i=0;i<q;i++) {
        scanf("%lld",&r);
        if(r<=l) {
            printf("%d %d\n",ans[r].first,ans[r].second);
        }
        else {
            r-=l;
            r%=(n-1);
            if(r==0) r=n-1;
            printf("%d %d\n",m,a[r]);
        }
    }
    return 0;
}